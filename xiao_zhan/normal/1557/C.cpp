#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,a[200500],b[200500];
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll jc[1005000],inv[1005000];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll res,tmp,tmp2;

int main(){
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		if(m==0){
			puts("1");continue;
		}
		res=0;
		
		if(!(n&1)){
			tmp=1;
			tmp2=0;
			for(i=0;i<n;i+=2){
				tmp2+=c(n,i);
				tmp2%=M;
			}
			for(i=m;i>=1;i--){
				res+=ksm(ksm(2,i-1),n)*tmp%M;
				res%=M;
				tmp=tmp*tmp2%M;
			}
			res+=tmp;
			printf("%lld\n",res%M);
		}
		else{
			tmp=1;
			tmp2=1;
			for(i=0;i<=n;i+=2){
				tmp2+=c(n,i);
				tmp2%=M;
			}
			for(i=m;i>=1;i--){
				tmp=tmp*tmp2%M;
			}
			res+=tmp;
			printf("%lld\n",res%M);
		}
	}
}