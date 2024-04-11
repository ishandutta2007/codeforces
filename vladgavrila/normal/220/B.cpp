#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define maxn 100010

int n, m, cr, pzq;
int aint[4*maxn];
int v[maxn], prv[maxn], sz[maxn], sol[maxn];
vector<int> pz[maxn];
pair<pair<int, int>, int> q[maxn];

inline int cmp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
    return a.first.second<b.first.second;
}

void update(int nod, int left, int right, int qleft, int qright, int val)
{
    if(qleft<=left && right<=qright)
    {
        aint[nod]+=val;
        return;
    }

    int med=(left+right)/2;

    if(qleft<=med)
        update(nod*2, left, med, qleft, qright, val);
    if(med<qright)
        update(nod*2+1, med+1, right, qleft, qright, val);
}

int query(int nod, int left, int right, int poz)
{
    if(left==right)
        return aint[nod];

    int med=(left+right)/2;

    if(poz<=med)
        return aint[nod]+query(nod*2, left, med, poz);
    return aint[nod]+query(nod*2+1, med+1, right, poz);
}

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &m);

    for(int i=1; i<=n; ++i)
    {
        pz[i].push_back(0);
        scanf("%d", &v[i]);
    }

    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d", &q[i].first.first, &q[i].first.second);
        q[i].second=i;
    }

    sort(q+1, q+m+1, cmp);

    pzq=1;

    for(int i=1; i<=n; ++i)
    {
        cr=v[i];
        if(cr<=n)
        {
            pz[cr].push_back(i);
            ++sz[cr];

            if(sz[cr]>=cr)
            {
           //     printf("%d\n", pz[cr][sz[cr]-cr]);
                update(1, 1, n, pz[cr][sz[cr]-cr]+1, pz[cr][sz[cr]-cr+1], 1);
            }
            if(sz[cr]>cr)
            {
              //   printf("%d\n", pz[cr][sz[cr]-cr-1]);
                 update(1, 1, n, pz[cr][sz[cr]-cr-1]+1, pz[cr][sz[cr]-cr], -1);

            }
        }

        while(q[pzq].first.second==i && pzq<=m)
        {
            sol[q[pzq].second]=query(1, 1, n, q[pzq].first.first);
            ++pzq;
        }
    }

    for(int i=1; i<=m; ++i)
        printf("%d\n", sol[i]);

    return 0;
}