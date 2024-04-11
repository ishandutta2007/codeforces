#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define CL(a,x) memset(a, x, sizeof(a))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 1e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,p[N],np[N];

int pw(LL x,int n){
	LL res = 1;
	for(;n;n>>=1,x=x*x%P)if(n&1)res=res*x%P;
	return res;
}

int main(){
	//freopen("test.in","r",stdin);
	cin>>n;
	memset(p,0,sizeof p);
	memset(np,0,sizeof np);
	rep(i,2,n){
		for(int j=2;j*j<=i;++j)
			if(i%j==0){ p[i] = j; break; }
		if(p[i]==0) p[i] = i;
	}
	np[1] = 0;
	rep(i,2,n){
		int x = i;
		while(x>1){
			int y = p[x];
			if((x/y) % y == 0){
				np[i] = 0; break;
			}
			x /= y, ++np[i];
		}
		//cout<<i<<" "<<p[i]<<" "<<np[i]<<endl;
	}
	LL ans = 1, invn = pw(n, P-2);
	rep(i,1,n)if(np[i]){
		LL oc = n / i * invn % P;
		oc = oc * pw(P+1-oc, P-2) % P;
		ans = np[i]%2==1 ? ans+oc : ans-oc;
		ans = (ans + P) % P;
	}
	cout<<ans<<endl;
	return 0;
}