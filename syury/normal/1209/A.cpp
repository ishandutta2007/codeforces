//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = 111;
int a[N];
bool alive[N];
int n;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin >> n;
    F(i, 0, n){
        alive[i] = 1;
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    F(i, 0, n){
        if(!alive[i])cont;
        alive[i] = 0;
        ++ans;
        F(j, i, n){
            if(a[j]%a[i] == 0)
                alive[j] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}