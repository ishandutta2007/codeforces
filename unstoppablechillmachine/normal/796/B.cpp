#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define sec second
#define fro for
#define itn int
#define pb push_back
#define make_pair mk
#define pii pair<int,int>
#define pll pair<ll,ll>


struct g
{
    int from, to, cost;
};

struct coor
{
    int x, y;
};

vector<int> Vec, Vec1, arr1;
set<int> st, st1;
map<int, int> mp;
queue<int> q;
deque<int> d;
string s, s1, s2;
stringstream str;
bool t, t1, t2, arr[1000001];
char ch, ch1, ch2;
pii p, p1;
int n, m, k, k1, a, b, l, r, mid, sum, kol, ans, max1, min1 = 1e9, v;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    cin >> n >> m >> k;
    for (int i = 1; i <= m ; i++)
    {
        cin >> a;
        arr[a] = true;
    }

    ans = 1;
    if (arr[1])
    {
        cout << 1;
        exit(0);
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> a >> b;
        if (ans == a) ans = b;
        else if (ans == b) ans = a;
        if (arr[ans]) break;
    }

    cout << ans;


    return 0;
}