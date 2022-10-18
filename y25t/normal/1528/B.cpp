#include<cstdio>
#include<algorithm>
#define P 998244353
#define N 1000005

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k){
	if(k<0)
		return 1;
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

int n;

int pr[N],_pr,d[N],cnt[N];
bool npr[N];
inline void si(int x){
	d[1]=1;
	for(int i=2;i<=x;i++){
		if(!npr[i]){
			pr[++_pr]=i;
			d[i]=2;
			cnt[i]=1;
		}
		for(int j=1;j<=_pr&&i*pr[j]<=x;j++){
			npr[i*pr[j]]=1;
			if(i%pr[j]==0){
				d[i*pr[j]]=d[i]/(cnt[i]+1)*(cnt[i]+2);
				cnt[i*pr[j]]=cnt[i]+1;
				break;
			}
			d[i*pr[j]]=d[i]*d[pr[j]];
			cnt[i*pr[j]]=1;
		}
	}
}

int ans;

int main(){
	scanf("%d",&n);
	si(n);
	ans=fp(2,n-1);
	for(int i=1;i<=n;i++)
		ans=fmo(ans+1ll*(d[i]-1)*fp(2,n-i-1)%P-P);
	printf("%d\n",ans);
}