#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=300005,mod=998244353,inv2=(mod+1)/2;
int n,m,ans,tot,iv,iv4;
int mul[maxn];
vector<int>a[maxn];
string s;
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	iv4=ksm(4,mod-2),iv=1ll*ksm(iv4-1,mod-2)*iv4%mod;
	mul[0]=1;
	for(int i=1;i<=300000;i++)
		mul[i]=1ll*mul[i-1]*iv4%mod;
	for(int i=1;i<=n;i++){
		a[i].resize(m),cin>>s;
		for(int j=0;j<m;j++)
			a[i][j]=s[j]=='o',tot+=a[i][j];
	}
	for(int i=1;i<=n;i++){
		int lst=-1;
		for(int j=0;j+1<m;j++){
			if(a[i][j]==0)
				lst=j;
			else if(a[i][j+1]==1){
				int k=(j-lst)/2-1;
				if((j-lst)%2==1)
					ans=(ans+1ll*mul[(j-lst-1)/2]*iv4)%mod;
				if(k>=0)
					ans=(ans+1ll*(mul[k+1]-1+mod)%mod*iv%mod*inv2)%mod;
			}
		}
	}
	for(int j=0;j<m;j++){
		int lst=0;
		for(int i=1;i+1<=n;i++){
			if(a[i][j]==0)
				lst=i;
			else if(a[i+1][j]==1){
				int k=(i-lst)/2-1;
				if((i-lst)%2==1)
					ans=(ans+1ll*mul[(i-lst-1)/2]*iv4)%mod;
				if(k>=0)
					ans=(ans+1ll*(mul[k+1]-1+mod)%mod*iv%mod*inv2)%mod;
			}
		}
	}
	while(tot--)
		ans=(ans+ans)%mod;
	printf("%d\n",ans);
	return 0;
}