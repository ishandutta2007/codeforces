#include<cstdio>
#include<algorithm>
#define maxn 55
#define INF 20000005
using namespace std;
char txt[maxn][maxn];
int pre[maxn][3];
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	int n,m;
	char ch;
	scanf("%d%d%c",&n,&m,&ch);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			scanf("%c",&txt[i][j]);
		scanf("%c",&ch);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			pre[i][j]=INF;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if('0'<=txt[i][j]&&txt[i][j]<='9')
				pre[i][0]=min(pre[i][0],min(j,m-j));
			else if('a'<=txt[i][j]&&txt[i][j]<='z')
				pre[i][1]=min(pre[i][1],min(j,m-j));
			else 
				pre[i][2]=min(pre[i][2],min(j,m-j));
		}
	}
	int ans=INF;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int l=0;l<n;l++){
				if(i==j||j==l||l==i)continue;
				ans=min(ans,pre[i][0]+pre[j][1]+pre[l][2]);
			}
	printf("%d",ans);
	return 0;
}