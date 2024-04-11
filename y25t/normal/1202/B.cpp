#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f
#define N 2000005

char s[N];

int n;

int cnt[15][15][15];
inline void pre(){
	memset(cnt,0x3f,sizeof(cnt));
	for(int k=0;k<10;k++)
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				for(int a=0;a<10;a++)
					for(int b=0;b<10;b++)
						if((a*i+b*j)%10==k&&a+b>0)
							cnt[k][i][j]=std::min(cnt[k][i][j],a+b-1);
}

int ans[15][15];

int main(){
	pre();
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int k=2;k<=n;k++)
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				ans[i][j]=(cnt[(s[k]-s[k-1]+10)%10][i][j]==inf||ans[i][j]==-1)?-1:ans[i][j]+cnt[(s[k]-s[k-1]+10)%10][i][j];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
}