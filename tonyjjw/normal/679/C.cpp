#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MN = 500 + 5;

int N,K,G;
char arr[MN][MN];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int vis[MN][MN];
int sz[MN*MN];
int gcnt[MN*MN];
int col[MN][MN];

bool chk(int x,int y){
	return x>=0 && y>=0 && x<N && y<N;
}
void dfs(int i,int j){
	vis[i][j]=1;
	col[i][j]=G;
	sz[G]++;
	for(int k=0;k<4;k++){
		int nx=i+dx[k], ny=j+dy[k];
		if(!chk(nx,ny))continue;
		if(vis[nx][ny])continue;
		if(arr[nx][ny]=='X')continue;
		dfs(nx,ny);
	}
}

int cur_val;
inline void gpush(int i,int j){
	if(!chk(i,j))return;
	if(arr[i][j]=='X')return;
	gcnt[col[i][j]]++;
	if(gcnt[col[i][j]]==1){
		cur_val += sz[col[i][j]];
	}
}
inline void gpop(int i,int j){
	if(!chk(i,j))return;
	if(arr[i][j]=='X')return;
	gcnt[col[i][j]]--;
	if(gcnt[col[i][j]]==0){
		cur_val -= sz[col[i][j]];
	}
}
inline void push(int i,int j){
	if(!chk(i,j))return;
	if(arr[i][j]=='.')return;
	cur_val++;
}
inline void pop(int i,int j){
	if(!chk(i,j))return;
	if(arr[i][j]=='.')return;
	cur_val--;
}

int main(){
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++) scanf("%s",arr[i]);
	int ans=0;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(arr[i][j]=='.' && !vis[i][j]){
		dfs(i,j);
		if(ans<sz[G]) ans=sz[G];
		G++;
	}
	for(int i=0;i<N;i++){
		for(int j=-K;j<=N+1;j++){
			for(int k=i;k<i+K;k++){
				gpop(k,j-2);
				gpush(k,j+K);
				pop(k,j-1);
				push(k,j+K-1);
			}
			gpush(i-1,j+K-1);
			gpop(i-1,j-1);
			gpush(i+K,j+K-1);
			gpop(i+K,j-1);
			if(ans<cur_val) ans=cur_val;
		}
	}
	printf("%d\n",ans);
	return 0;
}