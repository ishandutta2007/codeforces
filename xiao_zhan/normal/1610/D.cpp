#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t,f[200500],cur;
ll jc[1005000],inv[1005000],p[1005000],res;

ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
int main() {
	ios::sync_with_stdio(0);
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	
	p[0]=1;
	for(i=1;i<=500000;i++){
		p[i]=p[i-1]*2%M;
	}
	
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>j;
		k=0;
		while(!(j&1)){
			k++;j>>=1;
		}
		f[k]++;
	}
	cur=n-f[0];
	res=su(p[n],M-1);
	for(i=1;i<=50;i++){
		cur-=f[i];
		for(j=1;j<=f[i];j+=2){
			res=su(res,M-c(f[i],j)*p[cur]%M);
		}
	}
	
	/*for(i=0;i<=20;i++){
		printf("%d ",f[i]);
	}cout<<endl;*/
	
	cout<<res%M;
}