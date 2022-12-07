#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=200005;
int n,ans;
vector<int> e[N];
int f[N],g[N],fa[N];
int q[N],pre[N],suf[N];
void dfs1(int x){
	f[x]=1;
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dfs1(i);
		}
	*q=0;
	for (auto i:e[x])
		if (i!=fa[x])
			q[++*q]=f[i];
	sort(q+1,q+*q+1,greater<int>());
	for (int i=1;i<=*q;i++)
		f[x]=max(f[x],q[i]+i-1);
}
void dfs2(int x){
	*q=0;
	for (auto i:e[x])
		if (i!=fa[x])
			q[++*q]=f[i];
	if (x!=1)
		q[++*q]=g[x];
	sort(q+1,q+*q+1,greater<int>());
	pre[0]=suf[(*q)+1]=0;
	//cout<<x<<' '<<f[x]<<' '<<g[x]<<' '<<*q<<endl;
	//for (int i=1;i<=*q;i++) cout<<q[i]<<' '; cout<<endl;
	for (int i=1;i<=*q;i++)
		pre[i]=max(pre[i-1],q[i]+i-1);
	for (int i=*q;i>=1;i--)
		suf[i]=max(suf[i+1],q[i]+i-2);
	//for (int i=1;i<=*q;i++) cout<<pre[i]<<' '; cout<<endl;
	//for (int i=1;i<=*q;i++) cout<<suf[i]<<' '; cout<<endl;
	ans=max(ans,pre[*q]);
	for (int i=2;i<=*q;i++)
		ans=max(ans,(q[i]-1)+(q[1]-1)+i);
	for (auto i:e[x])
		if (i!=fa[x]){
			int p=lower_bound(q+1,q+*q+1,f[i],greater<int>())-q;
			g[i]=max(1,max(pre[p-1],suf[p+1]));
		}
	for (auto i:e[x])
		if (i!=fa[x])
			dfs2(i);
}
int co[N],p[N],vis[N],ffa[N];
bool cmp(int x,int y){
	return co[x]>co[y];
}
void dfs3(int x,int ff){
	ffa[x]=ff;
	for (auto i:e[x])
		if (i==ff) co[i]=-(1<<30);
		else if (fa[i]==x) co[i]=f[i];
		else if (fa[x]==i) co[i]=g[x];
		else assert(0);
	sort(e[x].begin(),e[x].end(),cmp);
	if (ff!=0){
		//cout<<"DEL "<<x<<' '<<e[x].back()<<endl;
		e[x].pop_back();
	}
	//cout<<x<<' '<<e[x].size()<<endl;
	p[x]=0;
	for (auto i:e[x])
		dfs3(i,x);//cout<<"EDGE "<<x<<' '<<i<<endl;
	//cout<<x<<' '<<e[x].size()<<endl;
}
vector<int> P;
int query(int x){
	cout<<"? "<<x<<endl;
	cin>>x;
	return x;
}
int getP(int x){
	for (;;){
		for (;p[x]<e[x].size()&&vis[e[x][p[x]]];++p[x]);
		if (p[x]>=e[x].size()) return x;
		x=e[x][p[x]];
	}
}
int solve(int x,int y){
	for (;;){
		//cout<<"P "<<x<<' '<<y<<' '<<ffa[y]<<endl;
		for (;y!=x;y=ffa[y]) vis[y]=1;
		//cout<<233<<endl;
		for (;p[x]<e[x].size()&&vis[e[x][p[x]]];++p[x]);
		//cout<<x<<' '<<p[x]<<' '<<e[x].size()<<endl;
		if (p[x]>=e[x].size()) return x;
		//cout<<x<<' '<<p[x]<<' '<<e[x][p[x]]<<endl;
		y=getP(e[x][p[x]]);
		x=query(y);
	}
}
int main(){
	ans=1;
	scanf("%d",&n);
	if (n==1){
		cout<<"0"<<endl;
		cout<<"! 1 1"<<endl;
		return 0; 
	}
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs1(1);
	dfs2(1);
	cout<<ans<<endl;
	int f;
	scanf("%d",&f);
	dfs3(f,0);
	
	//cout<<e[1].size()<<endl;
	for (int i=0;i<e[f].size();i++){
		int x=getP(e[f][i]);
		int p=query(x);
		if (p!=f) P.push_back(solve(p,x));
		if (P.size()==2) break;
	}
	for (;P.size()!=2;P.push_back(f));
	printf("! %d %d\n",P[0],P[1]);
}