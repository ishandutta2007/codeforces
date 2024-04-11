#include <bits/stdc++.h>
#define MAX_N 100100
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define LOWBIT(x) ( (x) & -(x) )

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int MAX = 1e5 + 10;
const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};

int test;
long long n , k; 
string s = ""; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r" , stdin);

    cin >> n >> k; 

    if (k == 0) {
        while (n--) {
            cout << "()"; 
        }

        return 0; 
    }

    if (n * (n - 1) / 2 < k) {
        cout << "Impossible"; 
        return 0; 
    }

    long long m = n; 

    for (int i = 1; i <= n; i++) {
        long long t = (long long) i * (long long) (i - 1) / 2; 
        if (t >= k) {
            m = i - 1; 
            break; 
        }
    }

    for (int i = 1; i <= n - m - 1; i++) {
        s += "()"; 
    }

    for (int i = 1; i <= m; i++) {
        s += "(";
        long long t = (ll) m * (ll) (m - 1) / 2; 
        if (k - t == i) {
            s += "()"; 
        } 
    }

    for (int i = 1; i <= m; i++) {

        s += ")"; 
    }

    cout << s; 

    return 0;
}