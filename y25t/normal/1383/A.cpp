#include<cstdio>
#include<cstring>
#define N 100005
#define M 25

int T;

int n;
char a[N],b[N];

bool g[M][M];

int f[M];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}

int main(){
	scanf("%d",&T);
	while(T--){
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		scanf("%d%s%s",&n,a+1,b+1);
		bool flg=1;
		for(int i=1;i<=n;i++){
			if(b[i]<a[i]){
				puts("-1");
				flg=0;
				break;
			}
			g[a[i]-'a'+1][b[i]-'a'+1]=1;
		}
		if(!flg)
			continue;
		int cnt=0;
		for(int i=1;i<=20;i++)
			for(int j=1;j<i;j++)
				if(g[j][i]){
					int fi=fnd(i),fj=fnd(j);
					if(fi!=fj){
						cnt++;
						f[fi]=fj;
					}
				}
		printf("%d\n",cnt);
	}
}