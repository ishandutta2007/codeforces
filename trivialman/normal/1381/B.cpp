#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 4005;
mt19937 rng(time(0));

int T, n;
int c[N], d[N];
bitset<N> f;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	
	while(T--){
		cin>>n;
		rep(i,1,2*n) cin>>c[i];
		int big = c[1], last = 1, m = 0;
		rep(i,2,n*2){
			if(c[i] > big){
				d[++m] = i - last;
				last = i;
				big = c[i];
			}
		}
		d[++m] = n*2+1 - last;
		
		f.reset();
		f[0] = 1;
		rep(i,1,m){
			f = f | (f << d[i]);
		}
		cout<<(f[n]?"YES":"NO")<<endl;
	}
	return 0;
}