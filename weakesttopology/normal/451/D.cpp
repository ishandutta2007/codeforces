#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

pll sum(pll x, pll y)
{
    return { x.f + y.f, x.s + y.s };
}

int main()
{ _
    string S; cin >> S;
    int n = S.size();
    vector<vpll> A(n, vpll(4, mp(0, 0)));

    A[0][0] = {0, S[0] == 'a'};  // a-a
    A[0][1] = {0, S[0] == 'b'};  // b-b
    A[0][2] = {0, 0};            // a-b
    A[0][3] = {0, 0};            // b-a

    for (int i = 1; i < n; ++i)
    {
        int x = S[i] == 'b';

        pll v = sum(A[i - 1][x], A[i - 1][2 + x]);
        A[i][x] = { v.s, v.f + 1LL};
        A[i][!x] = {0, 0};
        A[i][2 + x] = {0, 0};

        pll w = sum(A[i - 1][!x], A[i - 1][2 + !x]);
        A[i][2 + !x] = { w.s, w.f };
    }

    ll even = 0, odd = 0;
    for (int i = 0; i < n; ++i)
    {
        even += A[i][0].f + A[i][1].f;
        odd += A[i][0].s + A[i][1].s;
    }

    cout << even << " " << odd << endl;


    exit(0);
}