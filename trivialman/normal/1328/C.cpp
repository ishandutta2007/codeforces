#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
#define vs vector<string>
typedef long long LL;
const LL P = 998244353;
const int N = 50005;
mt19937 rng(time(0));

int T, n, k;
char a[N], b[N], c[N];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		cin>>n;
		cin>>(c+1);
		bool eq = true;
		rep(i,1,n) if(eq) {
			if(c[i]=='0') a[i] = b[i] = '0';
			if(c[i]=='2') a[i] = b[i] = '1';
			if(c[i]=='1') a[i] = '1', b[i] = '0', eq = false;
		}else{
			a[i] = '0', b[i] = c[i];
		}
		a[n+1] = b[n+1] = 0;
		cout<<(a+1)<<endl<<(b+1)<<endl;
	}
	
	return 0;
}