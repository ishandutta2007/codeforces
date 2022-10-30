//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define I(x, a) for(auto x : (a))
#define all(x) (x).begin(),(x).end()
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

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const int N = (int)1e5 + 5;

int n, k;
int a[N];

int gr(int x){
	if(x&1){
		return x < 5 ? 1 : 0;
	}
	if(x == 2)return 0;
	if(x == 4)return 2;
	int kek = gr(x/2);
	if(kek == 1)return 2;
	else return 1;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	F(i, 0, n)cin >> a[i];
	if(!(k&1)){
		int x = 0;
		F(i, 0, n){
			int v = a[i] < 3 ? a[i] == 1 ? 1 : 2 : (1^(a[i]&1));
			x ^= v;
		}
		if(x)cout << "Kevin";
		else cout << "Nicky";
	}
	else{
		int x = 0;
		F(i, 0, n){
			x ^= gr(a[i]);
		}
		if(x)cout << "Kevin";
		else cout << "Nicky";
	}
	return 0;
}