#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 300100;

int next[N][26], fail[N], end[N], t[N], pos[N], v[N];
int root[30], L, tim;
string s[N];
stack <int> st;
vector <int> id[30];
int newnode ()
{
    int now;
    if (!st.empty ()) {
        now = st.top();
        st.pop();
    }
    else now = L++;
    for (int i = 0; i < 26; i++)
        next[now][i] = -1;
    end[now] = 0;
    return now;
}


void del (int rt) {
    if (v[rt] == tim) return;
    v[rt] = tim;
//    cout << rt << endl;
    st.push (rt);
    for (int i = 0; i < 26; i++) if (next[rt][i] != -1) {
        del (next[rt][i]);
    }
}

void insert(int x, string buf, int c)
{
    int len = buf.length ();
    int now = root[x];
    for(int i = 0;i < len;i++)
    {
        if(next[now][buf[i]-'a'] == -1)
            next[now][buf[i]-'a'] = newnode();
        now = next[now][buf[i]-'a'];
    }
//    pos[id] = now;
//    cout << id << ' ' << now << endl;
    end[now] += c;
}

vector <int> g[N];

void build (int x)
{
    queue<int>Q;
    fail[root[x]] = root[x];
    for(int i = 0;i < 26;i++)
        if(next[root[x]][i] == -1)
            next[root[x]][i] = root[x];
        else
        {
            fail[next[root[x]][i]] = root[x];
//            g[next[root[x]][i]].push_back (root[x]);
//            g[root].push_back (next[root[x]][i]);
            Q.push(next[root[x]][i]);
        }
    while( !Q.empty() )
    {
        int now = Q.front();
        Q.pop();
        for(int i = 0;i < 26;i++)
            if(next[now][i] == -1)
                next[now][i] = next[fail[now]][i];
            else
            {
                fail[next[now][i]]=next[fail[now]][i];
                end[next[now][i]] += end[next[fail[now]][i]];
//                g[next[now][i]].push_back (next[fail[now]][i]);
//                g[next[fail[now]][i]].push_back (next[now][i]);
                Q.push(next[now][i]);
            }
    }
}

void init (int x)
{
//    L = 0;
    tim++;
    del (root[x]);
    root[x] = newnode ();
//    fail[root[x]] = root[x];
//    for (int i = 0; i < 26; i++) nx[root[x]] =
}

int tree[N];

int f (int x) { return x & -x; }
void add (int x, int y) {
    if ( x == 0) return ;
    for (int i = x; i; i -= f (i)) tree[i] += y;
}
int qry (int x) {
    int r = 0;
    for (int i = x; i < N; i += f (i)) r += tree[i];
    return r;
}

int nn, l[N], r[N];

void dfs (int u, int fa) {
//    cout << u << ' ' << fa << endl;
    l[u] = ++nn;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs (v, u);
    }
    r[u] = nn;
}

LL query (int x, string buf)
{
//    cout << x << ' ' << buf << endl;
    int len = buf.length ();
    int now = root[x];
    LL res = 0;
    for(int i = 0; i < len; i++)
    {
        now = next[now][buf[i]-'a'];
//        cout << now << "   " << end[now] << endl;
        res += end[now];
    }
    return res;
}

int a[30];

void solve (int x) {
    init (x);
//    cout << "solve " << x << endl;
    for (int i = 0; i < id[x].size(); i++) {
//        cout << x << ' ' << i << endl;
        insert (x, s[id[x][i]], (t[id[x][i]] == 1 ? 1 : -1));
    }
    build (x);
}


void init()
{
    L = 0;
    for (int i = 0; i < 20; i++) {
        root[i] = newnode ();
        build (i);
    }
}

int main ()
{
    ios::sync_with_stdio (0);
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    init ();
//    for (int i = 1; i <= n; i++) {
////        cout << t[i] << ' ' << s[i] << endl;
////        if (t[i] < 3) insert (i, s[i]);
//    }
//    build ();
//    dfs (0, 0);
    for (int o = 1; o <= n; o++) {
        cin >> t[o] >> s[o];
        if (t[o] <= 2) {
            id[0].push_back (o);
            for (int i = 0; i < 20; i++) {
//                cout << i << ' ' << id[i].size() << endl;
                if (id[i].size() > (1 << i)) {
                    for (int j = 0; j < id[i].size(); j++) {
//                        cout << j << endl;
                        id[i + 1].push_back (id[i][j]);
                    }
                    id[i].clear();
                    init (i);
                    build (i);
                } else {
                    solve (i);
                    break;
                }
            }
//            cout << l[pos[i]] << ' ' << r[pos[i]] << endl;
        }
//        else if (t[i] == 2) {
//            add (r[pos[i]], -1);
//            add (l[pos[i]] - 1, 1);
//        }
        else {
//            cout << "   " << i << endl;
            LL res = 0;
            for (int k = 0; k < 20; k++) {
                res += query (k, s[o]);
            }
            cout << res << endl;
            cout.flush ();
        }
    }
    return 0;
}