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

vector<int> Vec, Vec1, arr, arr1;
set<int> st, st1;
map<int, int> mp;
queue<int> q;
deque<int> d;
string s, s1, s2;
stringstream str;
bool t, t1, t2;
char ch, ch1, ch2;
pii p, p1;
int n, m, k, k1, a, l, r, mid, sum, kol, ans, max1, min1 = 1e9, v;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    cin >> n >> m >> k;
    arr.resize(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++)
    {
        if (i == m) continue;
        if (arr[i] <= k && arr[i] != 0) min1 = min(min1, abs(m - i) * 10);
    }

    cout << min1;




    return 0;
}