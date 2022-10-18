#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#define N 1005

int n,m,q;
char str[N];
bool a[N][N];

std::vector<std::pair<int,int> > del;

int num[N][N],tot,ld,ru;

std::set<std::pair<int,int> > s;

namespace FU {
	int f[N*N];
	std::vector<int> inv[N*N];
	std::set<int> su;
	void init(int i) {
		if(su.count(i))
			return;
		su.insert(i);
		f[i] = i;
		inv[i].push_back(i);
	}
	void mrg(int u,int v) {
		init(u);
		init(v);
		u=f[u];
		v=f[v];
		if(u==v)
			return;
		for(int i=0;i<inv[u].size();i++) {
			f[inv[u][i]]=v;
			inv[v].push_back(inv[u][i]);
		}
		inv[u].clear();
	}
	bool cnn(int u, int v) {
		init(u);
		init(v);
		return f[u]==f[v];
	}
	void cl() {
		for(std::set<int>::iterator i=su.begin();i!=su.end();i++) {
			f[*i]=0;
			inv[*i].clear();
		}
		su.clear();
	}
}
using namespace FU;

inline void dfs(int x,int y,int id){
	num[x][y]=id;
	for(int i=x-1;i<=x+1;i++)	
		for(int j=y-1;j<=y+1;j++)
			if(a[i][j]&&!num[i][j])
				dfs(i,j,id);
}

inline void R1(int x,int y){
	for(int i=x-1;i<=x+1;i++)
		for(int j=y-1;j<=y+1;j++)
			if(0<=i&&i<=n+1&&0<=j&&j<=m+1&&num[i][j])
				mrg(num[x][y],num[i][j]);
}
inline void R2(int x,int y){
	for(int i=x-2;i<=x+2;i++)
		for(int j=y-2;j<=y+2;j++)
			if(0<=i&&i<=n+1&&0<=j&&j<=m+1&&num[i][j]&&num[x][y]!=num[i][j])
				s.insert(std::make_pair(num[x][y],num[i][j]));
}
inline bool chk(int x,int y){
	for(int i=x-2;i<=x+2;i++)
		for(int j=y-2;j<=y+2;j++)
			if(0<=i&&i<=n+1&&0<=j&&j<=m+1&&num[i][j])
				if((cnn(num[x][y],ld)&&cnn(num[i][j],ru))||(cnn(num[x][y],ru)&&cnn(num[i][j],ld)))
					return 1;
	return 0;
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=3;i<=n+1;i++)
		a[i][0]=1;
	for(int i=1;i<=n-2;i++)
		a[i][m+1]=1;
	for(int i=3;i<=m+1;i++)
		a[0][i]=1;
	for(int i=1;i<=m-2;i++) 
		a[n+1][i]=1;
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)
			a[i][j]=str[j]=='#';
	}
//	for(int i=0;i<=n+1;i++){
//		for(int j=0;j<=m+1;j++)
//			printf("%4d ",a[i][j]);
//		puts("");
//	}
//	puts("");
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			if(a[i][j]&&!num[i][j])
				dfs(i,j,++tot);
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			if(num[i][j])
				R2(i,j);
	ld=num[3][0];
	ru=num[0][3];
//	for(int i=0;i<=n+1;i++){
//		for(int j=0;j<=m+1;j++)
//			printf("%4d ",num[i][j]);
//		puts("");
//	}
	while(q--){
		cl();
		init(ld);
		init(ru);
		del.clear();
		int k;
		scanf("%d",&k);
		int lst=tot;
		bool flg=1;
		for(int i=1;i<=k;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			num[x][y]=++tot;
			R1(x,y);
			del.push_back(std::make_pair(x,y));
		}
		for(std::set<int>::iterator i=su.begin();i!=su.end();i++)
			for(std::set<int>::iterator j=su.begin();j!=su.end();j++)
				if(cnn(*i,ld)&&cnn(*j,ru)&&(s.count(std::make_pair(*i,*j))||s.count(std::make_pair(*j,*i))))
					flg=0;
		for(std::vector<std::pair<int,int> >::iterator it=del.begin();it!=del.end();it++)
			if(chk(it->first,it->second))
				flg=0;
		puts(flg?"YES":"NO");
		fflush(stdout);
		for(std::vector<std::pair<int,int> >::iterator it=del.begin();it!=del.end();it++)
			num[it->first][it->second]=0;
		tot-=k;
	}
}
/*
8 5 2
.....
..#..
..#..
.#...
.....
..#..
..#..
.....
2
1 3
8 3
1
1 3
*/