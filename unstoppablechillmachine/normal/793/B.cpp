#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const INF=1000000000;
ll const BINF=1000000000000000000;
int const MAXN = 1e6  + 10;
ld const EPS = -0.0000000000000001;

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

set<pii> st;
bool arr[1010][1010], t;
char ch;
int n, m, x, nx, nx1, tox, y, ny, ny1, toy;

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
        if (ch == '*')
        {
            arr[i][j] = 1;
        }
        else
        {
            arr[i][j] = 0;
            if (ch == 'S')
            {
                nx = j;
                ny = i;
            }
            else
            {
                if (ch == 'T')
                {
                    tox = j;
                    toy = i;
                }
            }
        }
    }
    nx1 = nx;
    while(nx1 && !arr[ny][nx1])
    {
        st.insert(mk(ny, nx1));
        nx1--;
    }
    nx1 = nx;
    while (nx1 <= m  && !arr[ny][nx1])
    {
        st.insert(mk(ny, nx1));
        nx1++;
    }

    ny1 = ny;
    while(ny1  && !arr[ny1][nx])
    {
        st.insert(mk(ny1, nx));
        ny1--;
    }

    ny1 = ny;
    while (ny1 <= n  && !arr[ny1][nx])
    {
        st.insert(mk(ny1, nx));
        ny1++;
    }

    for(set<pii>::iterator it = st.begin(); it != st.end(); it++)
    {
        y = it -> f;
        x = it -> sec;
        nx1 = x;
        ny1 = y;
        if (x <= tox && y <= toy)
        {
            while (nx1 < tox && nx1 < m && !arr[ny1][nx1 + 1]) nx1++;
            while (ny1 < toy && ny1 < n && !arr[ny1 + 1][nx1]) ny1++;
            if (nx1 == tox && ny1 == toy) t = true;

            nx1 = x;
            ny1 = y;
            while (ny1 < toy && ny1 < n && !arr[ny1 + 1][nx1]) ny1++;
            while (nx1 < tox && nx1 < m && !arr[ny1][nx1 + 1]) nx1++;

            if (nx1 == tox && ny1 == toy) t = true;
        }

        else if (x >= tox && y <= toy)
        {
            while (nx1 > tox && nx1 > 1 && !arr[ny1][nx1 - 1]) nx1--;
            while (ny1 < toy && ny1 < n && !arr[ny1 + 1][nx1]) ny1++;
            if (nx1 == tox && ny1 == toy) t = true;

            nx1 = x;
            ny1 = y;
            while (ny1 < toy && ny1 < n && !arr[ny1 + 1][nx1]) ny1++;
            while (nx1 > tox && nx1 > 1 && !arr[ny1][nx1 - 1]) nx1--;

            if (nx1 == tox && ny1 == toy) t = true;
        }

        else if (x <= tox && y >= toy)
        {
            while (nx1 < tox && nx1 < m && !arr[ny1][nx1 + 1]) nx1++;
            while (ny1 > toy && ny1 > 1 && !arr[ny1 - 1][nx1]) ny1--;
            if (nx1 == tox && ny1 == toy) t = true;

            nx1 = x;
            ny1 = y;
            while (ny1 > toy && ny1 > 1 && !arr[ny1 - 1][nx1]) ny1--;
            while (nx1 < tox && nx1 < m && !arr[ny1][nx1 + 1]) nx1++;

            if (nx1 == tox && ny1 == toy) t = true;
        }
        else
        {
            while (nx1 > tox && nx1 > 1 && !arr[ny1][nx1 - 1]) nx1--;
            while (ny1 > toy && ny1 > 1 && !arr[ny1 - 1][nx1]) ny1--;
            if (nx1 == tox && ny1 == toy) t = true;

            nx1 = x;
            ny1 = y;
            while (ny1 > toy && ny1 > 1 && !arr[ny1 - 1][nx1]) ny1--;
            while (nx1 > tox && nx1 > 1 && !arr[ny1][nx1 - 1]) nx1--;

            if (nx1 == tox && ny1 == toy) t = true;
        }

    }

    if (t) cout << "YES";
    else cout << "NO";
    return 0;
}