#include<cstdio>
#include<algorithm>
#define N 1005

int T;

int n,m;
char s[N];

int a[N],b[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%s",&n,&m,s+1);
		m=std::min(m,2*n);
		for(int i=1;i<=n;i++)
			a[i]=s[i]-'0';
		a[0]=a[n+1]=0;
		while(m--){
			for(int i=1;i<=n;i++)
				if(!a[i]&&a[i-1]+a[i+1]==1)
					b[i]=1;
				else if(a[i])
					b[i]=1;
			for(int i=1;i<=n;i++)
				a[i]=b[i];
		}
		for(int i=1;i<=n;i++)
			putchar('0'+a[i]);
		puts("");
		for(int i=1;i<=n;i++)
			a[i]=b[i]=0;
	}
}