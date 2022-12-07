#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define Pset vector<pair<int,int> >
using namespace std;

Pset adj4(int x,int y){
	Pset re;
	re.push_back(pair<int,int>(x-1,y));
	re.push_back(pair<int,int>(x+1,y));
	re.push_back(pair<int,int>(x,y-1));
	re.push_back(pair<int,int>(x,y+1));
	return re;
}
Pset adj8(int x,int y){
	Pset re;
	re.push_back(pair<int,int>(x-1,y));
	re.push_back(pair<int,int>(x+1,y));
	re.push_back(pair<int,int>(x,y-1));
	re.push_back(pair<int,int>(x,y+1));
	re.push_back(pair<int,int>(x-1,y-1));
	re.push_back(pair<int,int>(x+1,y-1));
	re.push_back(pair<int,int>(x-1,y+1));
	re.push_back(pair<int,int>(x+1,y+1));
	return re;
}
const int N=505;
int n,m,col,qx[N*N],qy[N*N],q[N*N];
int bel[N][N],res[N][N],bi[N*N];
vector<int> adj[N*N];
char s[N][N];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]=='X'){
				int sum=0;
				Pset tmp=adj4(i,j);
				for (auto k:tmp) sum+=(s[k.first][k.second]=='.');
				if (sum&1) return puts("NO"),0;
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!bel[i][j]&&s[i][j]=='.'){
				bel[i][j]=++col;
				int h=0,t=1; qx[1]=i,qy[1]=j;
				while (h!=t){
					int x=qx[++h],y=qy[h];
					Pset tmp=adj8(x,y);
					for (auto k:tmp)
						if (s[k.first][k.second]=='.')
							if (!bel[k.first][k.second]){
								bel[k.first][k.second]=col;
								qx[++t]=k.first; qy[t]=k.second;
							}
				}
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (s[i][j]=='.') continue;
			if (s[i-1][j]=='.'&&s[i+1][j]=='.'&&bel[i-1][j]!=bel[i+1][j]){
				adj[bel[i-1][j]].push_back(bel[i+1][j]);
				adj[bel[i+1][j]].push_back(bel[i-1][j]);
			}
			if (s[i][j-1]=='.'&&s[i][j+1]=='.'&&bel[i][j-1]!=bel[i][j+1]){
				adj[bel[i][j-1]].push_back(bel[i][j+1]);
				adj[bel[i][j+1]].push_back(bel[i][j-1]);
			}
		}
	for (int i=1;i<=col;i++)
		if (!bi[i]){
			bi[i]=1;
			int h=0,t=1; qx[1]=i;
			while (h!=t){
				int x=qx[++h];
				for (auto i:adj[x])
					if (!bi[i]) bi[i]=bi[x]^3,qx[++t]=i;
					else if (bi[i]^bi[x]^3) return puts("N0"),0;
			}
		}
	for (int j=1;j<=m;j++){
		int cur=(j&1?4:1);
		res[1][j]=cur;
		int prev=bi[bel[1][j]];
		for (int i=2;i<=n;i++){
			if (s[i][j]=='.'){
				if (bi[bel[i][j]]!=prev)
					cur=5-cur;
				res[i][j]=cur;
				prev=bi[bel[i][j]];
			}
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]=='X'){
				Pset tmp=adj4(i,j);
				for (auto k:tmp) 
					if (s[k.first][k.second]=='.')
						res[i][j]+=res[k.first][k.second];
			}
	puts("YES");
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			printf("%d%c",res[i][j],j==m?'\n':' '); 
}