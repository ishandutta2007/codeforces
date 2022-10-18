#include<bits/stdc++.h>
#define P 1000000007
#define N 100005

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k=P-2){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

int pr[N],_pr,mu[N];
bool npr[N];
inline void si(int x){
	mu[1]=1;
	for(int i=2;i<=x;i++){
		if(!npr[i]){
			pr[++_pr]=i;
			mu[i]=P-1;
		}
		for(int j=1;j<=_pr&&i*pr[j]<=x;j++){
			npr[i*pr[j]]=1;
			if(i%pr[j]==0)
				break;
			mu[i*pr[j]]=fmo(-mu[i]);
		}
	}
}

int n,k;

int pw[N];

int ans;

int main(){
	scanf("%d%d",&n,&k);
	si(n);
	pw[0]=1;
	for(int i=1;i<=n;i++)
		pw[i]=1ll*pw[i-1]*k%P;
	for(int d=1;d<n;d++)
		for(int t=1;t<=(n-1)/d;t++){
			int x=(n-1)/d/t,tmp=0;
			for(int i=2;i<=2*x;i++)
				tmp=fmo(tmp+1ll*(x-std::abs(x+1-i))*pw[std::max(i*d*t-n,d)]%P-P);
			ans=fmo(ans+1ll*mu[t]*tmp%P-P);
		}
	ans=1ll*ans*fp(pw[n])%P;
	printf("%d\n",ans);
}