#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;
constexpr int n=666,m=999;
constexpr int mid=(m+1)/2;
pair<int,int>p[n+1];
bool board[m+1][m+1];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&p[i].first,&p[i].second);
	while(a!=mid||b!=mid){
		if(a>mid)
			--a;
		else
			if(a<mid)
				++a;
		if(b>mid)
			--b;
		else
			if(b<mid)
				++b;
		printf("%d %d\n",a,b);
		fflush(stdout);
		int k,x,y;
		scanf("%d%d%d",&k,&x,&y);
		if(k==-1)
			return 0;
		p[k].first=x,p[k].second=y;
	}
	int cnt[2][2]={{0,0},{0,0}};
	memset(board,0,sizeof(board));
	for(int i=1; i<=n; ++i)
		++cnt[int(p[i].first<mid)][int(p[i].second<mid)],board[p[i].first][p[i].second]=1;
	if(n-cnt[1][1]>m-mid){
		while(1){
			++a,++b;
			if(board[a][b])
				--a;
			printf("%d %d\n",a,b);
			fflush(stdout);
			int k,x,y;
			scanf("%d%d%d",&k,&x,&y);
			if(k<0)
				return 0;
			board[p[k].first][p[k].second]=0;
			p[k].first=x,p[k].second=y,board[x][y]=1;
		}
	}
	if(n-cnt[1][0]>m-mid){
		while(1){
			++a,--b;
			if(board[a][b])
				--a;
			printf("%d %d\n",a,b);
			fflush(stdout);
			int k,x,y;
			scanf("%d%d%d",&k,&x,&y);
			if(k<0)
				return 0;
			board[p[k].first][p[k].second]=0;
			p[k].first=x,p[k].second=y,board[x][y]=1;
		}
	}
	if(n-cnt[0][1]>m-mid){
		while(1){
			--a,++b;
			if(board[a][b])
				++a;
			printf("%d %d\n",a,b);
			fflush(stdout);
			int k,x,y;
			scanf("%d%d%d",&k,&x,&y);
			if(k<0)
				return 0;
			board[p[k].first][p[k].second]=0;
			p[k].first=x,p[k].second=y,board[x][y]=1;
		}
	}
	if(n-cnt[0][0]>mid-1){
		while(1){
			--a,--b;
			if(board[a][b])
				++a;
			printf("%d %d\n",a,b);
			fflush(stdout);
			int k,x,y;
			scanf("%d%d%d",&k,&x,&y);
			if(k<0)
				return 0;
			board[p[k].first][p[k].second]=0;
			p[k].first=x,p[k].second=y,board[x][y]=1;
		}
	}
	return 0;
}