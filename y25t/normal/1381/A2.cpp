#include<cstdio>
#define N 100005

int T;

int n,a[N],b[N];
char s[N];

int k,p[N<<1];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)
			a[i]=s[i]=='1';
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			b[i]=s[i]=='1';
		k=0;
		for(int i=n,j=1,tp=1;i;i--){
			if(a[j]^b[i]^tp)
				p[++k]=1;
			p[++k]=i;
			j=j<=n/2?n-j+1:n-j+2;
			tp^=1;
		}
		printf("%d ",k);
		for(int i=1;i<=k;i++)
			printf("%d ",p[i]);
		printf("\n");
	}
}