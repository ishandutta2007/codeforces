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

int idx[N],Col[N];
int q[N],spe[N],spe2[N];
vector<int> E[N];
int L[N],R[N],Jmp[N];
bool cmp(int x,int y){
	return Col[x]<Col[y];
}
void Topo(){
	memset(ind,0,sizeof(ind));
	for (int i=1;i<=*col;i++) ind[i]=0;
	for (int i=1;i<=*col;i++)
		for (auto j:E[i]) ++ind[j];
	int h=0,t=0;
	for (int i=1;i<=*col;i++)
		if (!ind[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		for (auto i:E[x]){
			spe2[i]|=spe2[x]|spe[x];
			if (!(--ind[i])) q[++t]=i;
		}
	}
	for (int i=1;i<=*col;i++)
		if (spe[i]&&!spe2[i]){
			idx[++*idx]=i;
			//cout<<i<<' '<<Col[i]<<endl;
		}
	if (!*idx){
		puts("0");
		exit(0);
	}
	sort(idx+1,idx+*idx+1,cmp);
	for (int i=1;i<=*col;i++)
		L[i]=(*idx)+1,R[i]=0;
	for (int i=1;i<=*idx;i++)
		L[idx[i]]=R[idx[i]]=i;
	for (int i=t;i>=1;i--)
		for (auto j:E[q[i]]){
			L[q[i]]=min(L[q[i]],L[j]);
			R[q[i]]=max(R[q[i]],R[j]);
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
				E[col[i]].push_back(col[j]);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (s[i][j]=='#') Col[col[id[i][j]]]=j;
	for (int j=0;j<m;j++){
		int x;
		scanf("%d",&x);
		for (int i=0;i<n;i++)
			if (s[i][j]=='#')
				if (!(--x)){
					//cout<<i<<' '<<j<<' '<<col[id[i][j]]<<endl;
					spe[col[id[i][j]]]=1;
					break;
				}
	}
	Topo();
	int ans=0;
	for (int i=1;i<=*idx;i++) Jmp[i]=-1;
	for (int i=1;i<=*col;i++) Jmp[L[i]]=max(Jmp[L[i]],R[i]);
	for (int i=1;i<=*idx;i++) Jmp[i]=max(Jmp[i],Jmp[i-1]);
	for (int p=1;p<=*idx;p=Jmp[p]+1) ++ans;
	cout<<ans<<endl;
}