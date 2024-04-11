/*














*/
/*
  !










*/
/*

















*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF = 1e9;
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
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(),ostream_iterator<int>(cout, " "))

int x, y, tx, ty, n, m, xx, yy;
bool used[101][101], slr, sdu, a[101][101];
queue<pii> q;
pii fr[101][101], p;
vector<char> ans;
char ch;

void check()
{
    if (x == tx && y == ty)
    {
        //cout << x << "      " << y;
        exit(0);
    }
}

void write(char ch)
{
    if (ch == 'L')
    {
        (slr ? cout << 'R' : cout << 'L');
    }
    if (ch == 'R')
    {
        (slr ? cout << 'L' : cout << 'R');
    }
    if (ch == 'U')
    {
        (sdu ? cout << 'D' : cout << 'U');
    }
    if (ch == 'D')
    {
        (sdu ? cout << 'U' : cout << 'D');
    }
    cout << endl;
    cout.flush();
}

void go(int x, int y, int x2, int y2)
{
    if (x >= 1 && y >= 1 && y <= n && x <= m && !a[y][x] && !used[y][x])
    {
        used[y][x] = true;
        q.push(mk(y,x));
        fr[y][x] = mk(x2, y2);
    }
}

void upd(pii p, int x, int y)
{
    if (p.f != x)
    {
        (p.f < x ? ans.pb('R') : ans.pb('L'));
    }
    else
    {
        (p.sec < y ? ans.pb('D') : ans.pb('U'));
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> m;
    forn(i, n)
    forn(j, m)
    {
        cin >> ch;
        if (ch == '*') a[i][j] = 1;
        if (ch == 'F')
        {
            tx = j;
            ty = i;
        }
    }

    //cout << tx << " " << ty << endl;

    if (n == 1)
    {
        forn(i, m)
        {
            write('R');
            cin >> y >> x;
            check();
        }

        forn(i, m)
        {
            write('L');
            cin >> y >> x;
            check();
        }
    }

    if (m == 1)
    {
        forn(i, n)
        {
            write('D');
            cin >> y >> x;
            check();
        }

        forn(i, n)
        {
            write('U');
            cin >> y >> x;
            check();
        }
    }

    if (!a[1][2])
    {
        write('R');
        cin >> y >> x;
        if (x == 1 && y == 1) slr = true;
        else
        {
            check();
            write('L');
            cin >> y >> x;
        }
        x = 1;
        while(a[2][x])
        {
            write('R');
            cin >> y >> x;
            check();
        }
        write('D');
        cin >> y >> x;
        check();
        if (y == 1) sdu = true;
        else
        {
            write('U');
            cin >> y >> x;
            check();
        }
    }
    else
    {
        write('D');
        cin >> y >> x;
        if (y == 1) sdu = true;
        else
        {
            check();
            write('U');
            cin >> y >> x;
        }
        while(a[y][2])
        {
            write('D');
            cin >> y >> x;
            check();
        }
        write('R');
        cin >> y >> x;
        check();
        if (x == 1) slr = true;
        else
        {
            write('L');
            cin >> y >> x;
            check();
        }
    }

    yy = y;
    xx = x;
    q.push(mk(y, x));
    used[y][x] = true;
    while(!q.empty())
    {
        y = q.front().f;
        x = q.front().sec;
        q.pop();
        go(x + 1, y, x, y);
        go(x - 1, y, x, y);
        go(x, y + 1, x, y);
        go(x, y - 1, x, y);
    }

    x = xx;
    y = yy;

    while (tx != x || ty != y)
    {
        p = fr[ty][tx];
        upd(p, tx, ty);
        tx = p.f;
        ty = p.sec;
    }

    reverse(ans.begin(), ans.end());
    fore(i, ans.size())
    {
        write(ans[i]);
        cin >> y >> x;
    }

    return 0;
}