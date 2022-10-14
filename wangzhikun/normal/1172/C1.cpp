#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int mpow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(mpow(a,b/2))) : sq(mpow(a,b/2)));}

int dp[55][55],ndp[55][55],a[55],w[55],inv[200020];
int n,m;
int main() {
	for(int i=0;i<10000;i++)inv[i] = mpow(i,mod-2);
	read(n);read(m);
	int csu[2] = {0};
	for(int i=0;i<n;i++){
		read(a[i]);
		if(!a[i])a[i]-=1;
	}
	for(int i=0;i<n;i++){
		read(w[i]);
		if(a[i] == 1){
			csu[1]+=w[i];
		}else{
			csu[0]+=w[i];
		}
	}
	for(int i=0;i<n;i++){
		set0(dp);
		dp[0][0] = 1;
		int ob = csu[0]-w[i]*(a[i] == -1),oc = csu[1]-w[i]*(a[i] == 1);
		//cout<<ob<<' '<<oc<<endl;
		for(int t=0;t<m;t++){
			set0(ndp);
			for(int x=0;x<=t;x++){
				for(int y=0;x+y<=t;y++){
					int ca = w[i]+(t-x-y)*a[i],cb = ob-x,cc = oc+y,ci = inv[ca+cb+cc];
					if(ca<0 || cb<0 || cc<0)continue;
					ndp[x][y] = add(ndp[x][y],mul(dp[x][y],mul(ca,ci)));
					ndp[x+1][y] = add(ndp[x+1][y],mul(dp[x][y],mul(cb,ci)));
					ndp[x][y+1] = add(ndp[x][y+1],mul(dp[x][y],mul(cc,ci)));
				}
			}
			memcpy(dp,ndp,sizeof(dp));
		}
		int ans = 0;
		for(int x=0;x<=m;x++){
			for(int y=0;x+y<=m;y++){
				int ca = w[i]+(m-x-y)*a[i];
				ans = add(ans,mul(ca,dp[x][y]));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}