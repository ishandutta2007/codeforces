#include<cstdio>
#include<algorithm>
#define N 55

int T;

int n,m;
char s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		bool f[2]={0,0};
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
				if(s[j]=='W')
					f[((i+j)&1)^1]=1;
				else if(s[j]=='R')
					f[(i+j)&1]=1;
		}
		if(f[0]&&f[1]){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				putchar(f[1]^((i+j)&1)?'W':'R');
			puts("");
		}
	}
}