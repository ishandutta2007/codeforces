#include<cstdio>
#include<algorithm>
#define P 1000000007
#define N 505

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

int n;

int cnt[N];

int ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		if(a>0)
			cnt[a]++;
	}
	ans=fmo(fp(2,n-1)-1);
	for(int i=1;i<=n;i++){
		ans=fmo(ans-fp(2,cnt[i]));
		ans=fmo(ans+1-P);
	}
	printf("%d\n",ans);
}