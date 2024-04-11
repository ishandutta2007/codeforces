#include<bits/stdc++.h>
#define ll long long
#define P 1000000007
#define N 15

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

int n,a[N],w[N][N];

int p[1<<N][N];

std::unordered_map<ll,int> f;
int g[1<<N];

int ans;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j)
				w[i][j]=1ll*a[i]*fp(a[i]+a[j])%P;
	for(int s=0;s<(1<<n);s++)
		for(int i=0;i<n;i++)
			if(!((s>>i)&1)){
				p[s][i]=1;
				for(int j=0;j<n;j++)
					if((s>>j)&1)
						p[s][i]=1ll*p[s][i]*w[i][j]%P;
//				printf("*%d\n",p[s][i]);
			}
	for(int s=0;s<(1<<n);s++){
		int x=((1<<n)-1)^s;
		for(int t=x;;t=(t-1)&x){
			int tmp=1;
			for(int i=0;i<n;i++)
				if((s>>i)&1)
					tmp=1ll*tmp*p[t][i]%P;
			f[s<<n|t]=tmp;
			if(!t)
				break;
		}
	}
	g[0]=0;
	for(int s=1;s<(1<<n);s++){
		int tmp=1;
		for(int t=(s-1)&s;;t=(t-1)&s){
			tmp=fmo(tmp-1ll*g[t]*f[t<<n|(s^t)]%P);
			if(!t)
				break;
		}
		g[s]=tmp;
//		printf("%d\n",tmp);
		ans=fmo(ans+1ll*__builtin_popcount(s)*g[s]%P*f[s<<n|(((1<<n)-1)^s)]%P-P);
	}
	printf("%d\n",ans);
}