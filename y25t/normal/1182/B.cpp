#include<cstdio>
#define N 505

int n,m;
bool a[N][N];

char s[N];

int cnt[2][N];
bool ans=1;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			if(s[j]=='*'){
				a[i][j]=1;
				cnt[0][i]++;
				cnt[1][j]++;
			}
	}
	int x=0,y=0;
	bool tmp=0;
	for(int i=1;i<=n;i++){
		if(!cnt[0][i]&&cnt[0][i-1])
			tmp=1;
		if(cnt[0][i]){
			if(tmp)
				ans=0;
			if(cnt[0][i]>1)
				if(x)
					ans=0;
				else
					x=i;
		}
	}
	tmp=0;
	for(int i=1;i<=m;i++){
		if(!cnt[1][i]&&cnt[1][i-1])
			tmp=1;
		if(cnt[1][i]){
			if(tmp)
				ans=0;
			if(cnt[1][i]>1)
				if(y)
					ans=0;
				else
					y=i;
		}
	}
	if(!a[x][y]||!x||!y||!cnt[0][x-1]||!cnt[0][x+1]||!cnt[1][y-1]||!cnt[1][y+1])
		ans=0;
	if(ans)
		printf("YES");
	else
		printf("NO");
}