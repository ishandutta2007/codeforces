#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1e9 + 10;
ll const BINF = 1e18 + 10;
int const MAXN = 1e6 + 10;
ld const EPS = 1e-6;

#define f first
#define sec second
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mk make_pair
#define fro for
#define itn int
#define forn(i, n) for (int i = 1; i <= n; i++)
#define fore(i, n) for (int i = 0; i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(ec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

int n, m, k, to[1001][1001], dist;
vector<char> ans;
char ch;
bool arr[1001][1001],used[1001][1001];
pii cur, now, v;
queue<pair<pii, int> > q;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> m >> k;
    forn(i, n)
    forn(j, m)
    {
        cin >> ch;
        if (ch == '*') arr[i][j] = 1;
        if (ch == 'X')
        {
            now.f = i;
            now.sec = j;
        }
        to[i][j] = INF;
    }

    to[now.f][now.sec] = 0;
    used[now.f][now.sec] = true;
    q.push(mk(now, 0));
    while(!q.empty())
    {
        v = q.front().f;
        dist = q.front().sec;
        q.pop();
        if (v.f + 1 <= n && !arr[v.f + 1][v.sec] && !used[v.f + 1][v.sec])
        {
            used[v.f + 1][v.sec] = true;
            to[v.f + 1][v.sec] = dist + 1;
            cur.f = v.f + 1;
            cur.sec = v.sec;
            q.push(mk(cur, dist + 1));
        }
        if (v.sec + 1 <= m && !arr[v.f][v.sec + 1] && !used[v.f][v.sec + 1])
        {
            used[v.f][v.sec + 1] = true;
            to[v.f][v.sec + 1] = dist + 1;
            cur.f = v.f;
            cur.sec = v.sec + 1;
            q.push(mk(cur, dist + 1));
        }
        if (v.f - 1 >= 1 && !arr[v.f - 1][v.sec] && !used[v.f - 1][v.sec])
        {
            used[v.f - 1][v.sec] = true;
            to[v.f - 1][v.sec] = dist + 1;
            cur.f = v.f - 1;
            cur.sec = v.sec;
            q.push(mk(cur, dist + 1));
        }
        if (v.sec - 1 >= 1 && !arr[v.f][v.sec - 1] && !used[v.f][v.sec - 1])
        {
            used[v.f][v.sec - 1] = true;
            to[v.f][v.sec - 1] = dist + 1;
            cur.f = v.f;
            cur.sec = v.sec - 1;
            q.push(mk(cur, dist + 1));
        }
    }

    cur = now;

    for (int i = k - 1; i >= 0; i--)
    {
        if (cur.f + 1 <= n && to[cur.f + 1][cur.sec] <= i)
        {
            cur.f++;
            ans.pb('D');
        }
        else if (cur.sec - 1 >= 1 && to[cur.f][cur.sec - 1] <= i)
        {
            cur.sec--;
            ans.pb('L');
        }
        else if (cur.sec + 1 <= m && to[cur.f][cur.sec + 1] <= i)
        {
            cur.sec++;
            ans.pb('R');
        }
        else if (cur.f - 1 >= 1 && to[cur.f - 1][cur.sec] <= i)
        {
            cur.f--;
            ans.pb('U');
        }
        else
        {
            cout << "IMPOSSIBLE";
            exit(0);
        }
    }

    chcpy(ans);




    return 0;
}