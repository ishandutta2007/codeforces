#define _CRT_SECURE_NO_WARNINGS

#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <set>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <complex>
#include <hash_map>
#include <hash_set>

using namespace std;

#define pb push_back
#define pob pop_back
#define itr iterator
#define rs resize
#define as assign
#define fs first
#define sc second
#define lwb lower_bound
#define upb upper_bound
#define mp make_pair
#define sz(a) (int)a.size()
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FOD(i, n) for (int i = n - 1; i >= 0; --i)

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <string> vs;
typedef vector <vs> vvs;
typedef vector <char> vc;
typedef vector <vc> vvc;
typedef vector <vvc> vvvc;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <vvl> vvvl;
typedef vector <vvvl> vvvvl;
typedef vector <vvb> vvvb;
typedef double db;
typedef long double ldb;
typedef vector <db> vdb;
typedef vector <vdb> vvdb;
typedef vector <vvdb> vvvdb;
typedef vector <ldb> vldb;
typedef pair <int, int> ii;
typedef pair <int, char> ic;
typedef pair <ll, ll> lll;
typedef pair <int, ll> il;
typedef pair <ll, int> li;
typedef vector <ii> vii;
typedef vector <ic> vic;
typedef vector <vic> vvic;
typedef vector <vii> vvii;
typedef vector <lll> vll;
typedef vector <vll> vvll;
typedef pair <ll, int> li;
typedef pair <ll, ll> lll;
typedef pair <int, ll> il;
typedef set <int> si;
typedef set <ll> sl;
typedef set <li> sli;
typedef set <il> sil;                                     
typedef set <lll> sll;
typedef set <ii> sii;
typedef set <pair <int, bool> > sib;
typedef vector <si> vsi;
typedef vector <sii> vsii;
typedef map <int, int> mii;
typedef map <string, int> msi;
typedef map <string, char> msc;
typedef map <char, int> mci;
typedef queue <int> qi;
typedef deque <int> di;
typedef stack <int> sti;

const db inf = 1e9 + 7;
const ldb eps = 1e-6;   
const int M = 100;
const int N = 100005;

ll a[N], q[N];

int main()
{        
    int n, m;
    scanf("%d", &m);
    ll p = (ll)1e9;
    for (int i = 0; i < m; ++i)
    {
        scanf("%I64d", &q[i]); 
        p = min(p, q[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%I64d", &a[i]);       
    sort(a, a + n);  
    ll s = 0;
    int j = 0;
    ll ans = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s >= p)
        {
            i -= min(i, 1); 
            s = 0;
            continue;
        }
        s++;
        ans += a[i];
    }
    printf("%I64d", ans);

    return 0;         
}