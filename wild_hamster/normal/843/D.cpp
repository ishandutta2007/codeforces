#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,w,m,Q, used[100500], start;
ll a[100500], b[100500], c[100500];
vector<pii> g[100500];
vector<ll> f[1000500];
long long d[100500];
long long hea[200500];
int new_w[100500], new_d[100500];
int hea2[200500];
int st[100500], sz[100500], cur_pos[100500];
int G[100500];
ll heapSize;
void add(pair<long long,int> value)
{
    hea[heapSize++] = value.X;
    int i = heapSize - 1;
    hea2[i] = value.Y;
    int parent = ((i - 1)>>1);
    while (i > 0 && hea[parent] < hea[i])
    {
        swap(hea[i], hea[parent]);
        swap(hea2[i], hea2[parent]);
        i = parent;
        parent = ((i - 1)>>1);
    }
}
void heapify(int i)
{
    int largestChild;

    for (; ; )
    {
        largestChild = i;

        if (hea[2 * i + 1] > hea[largestChild])
        {
            largestChild = 2 * i + 1;
        }

        if (hea[2 * i + 2] > hea[largestChild])
        {
            largestChild = 2 * i + 2;
        }

        if (largestChild == i)
        {
            break;
        }

        swap(hea[i], hea[largestChild]);
        swap(hea2[i], hea2[largestChild]);
        i = largestChild;
    }
}
pair<long long,int> getMax()
{
    pii result = mp(hea[0],hea2[0]);

    heapSize--;
    hea[0] = hea[heapSize];
    hea2[0] = hea2[heapSize];
    hea[heapSize] = -(long long)1e+18;
    heapify(0);
    return result;
}

inline unsigned int readUInt()
{
  int c = getc(stdin);
  unsigned int x = 0;
  while (c <= 32)
    c = getc(stdin);
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getc(stdin);
  return x;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> Q;
    for (i = 0; i <= 200000; i++)
        hea[i] = -(long long)1e+18;
    for (i = 0; i < m; i++)
    {
        int x,y,z;
        a[i] = readUInt();
        b[i] = readUInt();
        c[i] = readUInt();
    }
    int s = 1;
    for (i = 0; i < m; i++)
    {
        g[a[i]].push_back(mp(b[i], c[i]));
    }
    st[1] = 0;
    sz[1] = g[1].size();
    for (i = 2; i <= n; i++)
    {
        st[i] = cur_pos[i] = st[i-1] + g[i-1].size();
        sz[i] = g[i].size();
    }
    for (i = 0; i < m; i++)
    {
        G[cur_pos[a[i]]++] = i;
    }
    for (i = 1; i <= n; i++)
        d[i] = (long long)1e+18;
    d[s] = 0;
    for (i = 0; i < heapSize; i++)
        hea[i] = -(long long)1e+18;
    heapSize = 0;
    add(make_pair (0, s));
    while (heapSize) {
        pii tmp = getMax();
        int v = tmp.second; long long cur_d = -tmp.first;
        if (cur_d > d[v])  continue;

        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first;
            long long len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                add(make_pair (-d[to], to));
            }
        }
    }
    for (i = 0; i < m; i++)
        new_w[i] = min(100000000LL, c[i] + d[a[i]] - d[b[i]]);
    int last_test = 1;
    for (int ii = 0; ii < Q; ii++)
    {
        ll test;
        cin >> test;
        if (test == 1)
        {
            if (last_test == 2)
            {
                for (i = 0; i <= n; i++)
                {
                    new_d[i] = 10000000;
                }
                for (i = 0; i <= x; i++)
                    f[i].clear();
                f[0].push_back(1);
                new_d[1] = 0;
                for (i = 0; i <= x; i++)
                {
                    for (j = 0; j < f[i].size(); j++)
                    {
                        int v = f[i][j];
                        if (new_d[v] == i)
                        {
                            int tmp = st[v] + sz[v];
                            for (k = st[v]; k < tmp; k++)
                            {
                                int to = b[G[k]];
                                int val = new_w[G[k]];
                                if (i+val <= x && new_d[to] > i + val)
                                {
                                    new_d[to] = i + val;
                                    f[i+val].push_back(to);
                                }
                            }
                        }
                    }
                }
                for (i = 1; i <= n; i++)
                {
                    d[i] += new_d[i];
                }
                for (i = 0; i < m; i++)
                    new_w[i] = c[i] + d[a[i]] - d[b[i]];
            }
            ll t;
            cin >> t;
            if (d[t] >= (long long)1e+18) 
                cout << -1 << endl;
            else
                cout << d[t] << endl;
        } else
        {
            int tmp;
            if (last_test == 1)
                x = 0;
            cin >> tmp;
            for (i = 0; i < tmp; i++)
            {
                int y = readUInt();
                new_w[y-1]++;
                c[y-1]++;
            }
            x += tmp;
        }
        last_test = test;
    }
    return 0;
}