//determined
#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <cassert>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef unsigned long long ull;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}

int n,k,a[1010],dp[1010][1010] = {0},sud[1010][1010] = {0};

int main(){
	read(n);read(k);
	int mi = 1e9,ma = -1e9;
	for(int i=1;i<=n;i++){
		read(a[i]);
		ma = max(ma,a[i]);
		mi = min(mi,a[i]);
	}
	sort(a+1,a+n+1);
	int ans = 0;
	//cout<<233<<endl;
	for(int d = 1;d<=100010;d++){
		//cout<<233<<endl;
		for(int i=0;i<=n+5;i++)for(int j=0;j<=k+5;j++)dp[i][j] = sud[i][j] = 0;
		dp[0][0] = 1;sud[0][0] = 1;
		int p = 0;
		//cout<<233<<endl;
		for(int i=1;i<=n;i++){
			while(a[p+1]<=a[i]-d){
				//cout<<p<<' '<<a[p]<<' '<<<<endl;
				p++;
			}
			//cout<<234<<endl;
			//dp[i][0] = 1;
			sud[i][0] = 1;
			for(int j=1;j<=k;j++){
				//cout<<j<<endl;
				//cout<<p<<' '<<j-1<<endl;
				dp[i][j] = sud[p][j-1];
				sud[i][j] = add(sud[i-1][j],dp[i][j]);
				//cout<<"CC"<<i<<' '<<j<<' '<<dp[i][j]<<' '<<sud[i][j]<<endl;
			}
		}
		//cout<<"ECH"<<d<<' '<<sud[n][k]<<endl;
		ans = add(ans,sud[n][k]);
		//cout<<d<<' '<<ans<<endl;
		if(sud[n][k] == 0)break;
	}
	cout<<ans<<endl;
	return 0;
}