#include<cstdio>
#include<algorithm>
#include<unordered_map>
typedef long long ll;
const int P=(1<<30)-1-0;
int a,b,c,p[2005],vis[2005];std::unordered_map<ll,int>mmp[2005];
void sieve(int n){
	vis[0]=vis[1]=1;
	for(int i=2;i<=n;++i){
		if(!vis[i])p[++*p]=i;
		for(int j=1;j<=*p&&i*p[j]<=n;++j){
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
int dp(int kk1,int kk2,int kk3,int pid){
	if(pid==0)return 1;
	ll ha=1ll*kk1*(a+1)*(a+1)+1ll*kk2*(a+1)+kk3;
	if(mmp[pid].count(ha))return mmp[pid][ha];
	int ans=0;
	int k1=1,k2=1,k3=1,k4=0;
	while(k1<=kk1){
		k2=1;int k5=0;
		while(k2<=kk2){
			k3=1;int k6=0;
			while(k3<=kk3){
				(ans+=1ll*dp(kk1/k1,kk2/k2,kk3/k3,pid-1)*(k4+k5+k6+1)&P)&=P;
				k3*=p[pid],++k6;
			}
			k2*=p[pid],++k5;
		}
		k1*=p[pid],++k4;
	}
	return mmp[pid][ha]=ans;
}
int main(){
	scanf("%d%d%d",&a,&b,&c);
	if(a<b)a^=b^=a^=b;if(a<c)a^=c^=a^=c;
	sieve(a);
	printf("%d\n",dp(a,b,c,*p)); 
	return 0;
}