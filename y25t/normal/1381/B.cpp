#include<cstdio>
#include<algorithm>
#define N 2005

int T;

int n;

int m,sz[N],dp[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		m=0;
		for(int i=1,mx=0,tmp=0;i<=(n<<1)+1;i++,tmp++){
			int a;
			if(i<=(n<<1))
				scanf("%d",&a);
			else
				a=i;
			if(a>mx){
				mx=a;
				sz[m++]=tmp;
				tmp=0;
			}
		}
		m--;
		dp[0]=1;
		for(int i=1;i<=n;i++)
			dp[i]=0;
		for(int i=1;i<=m;i++)
			for(int j=n;j>=sz[i];j--)
				if(dp[j-sz[i]])
					dp[j]=1;
		if(dp[n])
			puts("YES");
		else
			puts("NO");
	}
}