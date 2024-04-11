#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t,p[1005000];
ll jc[1005000],inv[1005000],res;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n+1;i++){
		cin>>k;p[k]++;
		//printf("NMSL%d %d %d\n",i,k,c(k+i-1,i));
		res=su(res,c(k+i-1,i));
	}
	/*k=0;
	for(i=200000;i>=1;i--){
		k+=p[i];
		if(k){
			printf("a%d %d %d\n",i,k,c(k+i-1,i));
			res=su(res,c(k+i-1,i));
		}
	}*/
	cout<<res;
}