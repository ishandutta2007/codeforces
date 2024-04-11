#include<cstdio>
#include<algorithm>
#define N 3505

int T;

int n,m,k,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		m--;
		if(k>m)
			k=m;
		int ans=0;
		for(int i=0;i<=k;i++){
			int tmp=1e9;
			for(int j=0;j<=m-k;j++)
				tmp=std::min(tmp,std::max(a[i+j+1],a[n-(m-i-j)]));
			ans=std::max(ans,tmp);
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			a[i]=0; 
	}
}