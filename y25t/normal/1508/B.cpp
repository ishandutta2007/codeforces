#include<cstdio>
#include<algorithm>
#define ll long long
#define N 100005

int T;

int n;
ll k;

int b[N];

int p[N];

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++)
			p[i]=i;
		k--;
		for(int i=n;i>1&&k;i--,k>>=1)
			if(k&1)
				b[i]=1;
		for(int i=n;i;i--){
			int j=i;
			while(b[j])
				j--;
			std::reverse(p+j,p+i+1);
			i=j;
		}
		for(int i=1;i<=n;i++)
			b[i]=0;
		if(k){
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++)
			printf("%d ",p[i]);
		puts("");
	}
}