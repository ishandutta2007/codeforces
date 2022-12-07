#include<bits/stdc++.h>

using namespace std;

const int N=400005;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
string s[N];
int n,m,nd;
vector<int> id[N],idp[N];
vector<int> e[N];
int fa[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int dfn[N],low[N],col[N];
int inq[N],stk[N],ind[N];

void tarjan(int x){
	low[x]=dfn[x]=++*dfn;
	stk[++*stk]=x; inq[x]=1;
	for (auto i:e[x])
		if (!dfn[i]){
			tarjan(i);
			low[x]=min(low[x],low[i]);
		}
		else if (inq[i])
			low[x]=min(low[x],dfn[i]);
	if (low[x]==dfn[x]){
		++*col;
		int y=23333333;
		for (;y!=x;){
			y=stk[(*stk)--];
			col[y]=*col;
			inq[y]=0;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=n-1;i>=0;i--) cin>>s[i];
	for (int i=0;i<n;i++){
		id[i].resize(m);
		for (int j=0;j<m;j++)
			if (s[i][j]=='#')
				id[i][j]=++nd;
		idp[i].resize(m);
	}
	for (int i=1;i<=nd;i++)
		fa[i]=i;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (s[i][j]=='#')
				for (int d=0;d<4;d++){
					int ni=i+dx[d];
					int nj=j+dy[d];
					if (ni<0||ni>=n||nj<0||nj>=m||s[ni][nj]!='#') continue;
					fa[get(id[i][j])]=get(id[ni][nj]);
				}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (id[i][j]){
				id[i][j]=get(id[i][j]);
				//cout<<i<<' '<<j<<' '<<id[i][j]<<endl;
			}
	for (int j=0;j<m;j++){
		idp[0][j]=id[0][j];
		for (int i=1;i<n;i++)
			if (id[i][j]){
				if (idp[i-1][j])
					e[id[i][j]].push_back(idp[i-1][j]);
				idp[i][j]=id[i][j];
			}
			else
				idp[i][j]=idp[i-1][j];
	}
	for (int i=1;i<n;i++)
		for (int j=0;j<m;j++)
			if (id[i][j]){
				if (j!=0&&idp[i-1][j-1])
					e[id[i][j]].push_back(idp[i-1][j-1]);
				if (j!=m-1&&idp[i-1][j+1])
					e[id[i][j]].push_back(idp[i-1][j+1]);
			}
	for (int i=1;i<=nd;i++)
		if (get(i)==i)
			if (!dfn[i]) tarjan(i);
	for (int i=1;i<=nd;i++)
		for (auto j:e[i])
			if (col[i]!=col[j])
				++ind[col[j]];
	int ans=0;
	for (int i=1;i<=*col;i++)
		if (!ind[i]) ++ans;
	cout<<ans<<endl;
}