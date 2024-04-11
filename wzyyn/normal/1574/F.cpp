#include<bits/stdc++.h>

using namespace std;

const int N=300005;
const int mo=998244353;
int n,m,k,fa[N],fav[N];
int c[N],vis[N],pos[N];
int mnv[N],mxv[N],bad[N];
int f[N],q[N],s[N];
vector<int> fil[N],inq[N];
int get(int x){
	if (x==fa[x]) return x;
	int y=fa[x];
	fa[x]=get(fa[x]);
	fav[x]+=fav[y];
	return fa[x];
}
void merge(int x,int ny,int np){
	int y=vis[x],p=pos[x];
	int p1=get(y),p2=get(ny);
	if (p1==p2){
		if (fav[ny]+np!=fav[y]+p)
			bad[p1]=1;
	}
	else{
		fa[p2]=p1;
		bad[p1]|=bad[p2];
		fav[p2]=(fav[y]+p)-(fav[ny]+np);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		fa[i]=i;
	for (int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		inq[i].push_back(0);
		for (int j=1;j<=c[i];j++){
			int x;
			scanf("%d",&x);
			inq[i].push_back(x);
			if (!vis[x]){
				vis[x]=i;
				pos[x]=j;
			}
			else
				merge(x,i,j);
		}
	}
	for (int i=1;i<=n;i++)
		if (fa[i]==i) mnv[i]=1<<30;
	for (int i=1;i<=n;i++){
		get(i);
		int dif=fav[i];
		mnv[fa[i]]=min(mnv[fa[i]],dif+1);
		mxv[fa[i]]=max(mxv[fa[i]],dif+c[i]);
	}
	for (int i=1;i<=n;i++)
		if (fa[i]==i&&!bad[i])
			fil[i].resize(mxv[i]-mnv[i]+2);
	for (int i=1;i<=n;i++) if (!bad[fa[i]])
		for (int j=1;j<=c[i];j++){
			int p=fav[i]+j-mnv[fa[i]];
			if (fil[fa[i]][p]&&fil[fa[i]][p]!=inq[i][j]) bad[fa[i]]=1;
			fil[fa[i]][p]=inq[i][j];
		}
	for (int i=1;i<=n;i++)
		if (fa[i]==i&&!bad[i])
			++s[mxv[i]-mnv[i]+1];
	for (int i=1;i<=k;i++)
		if (!vis[i]) ++s[1];
	for (int i=1;i<=m;i++)
		if (s[i]) q[++*q]=i;
	f[0]=1;
	for (int i=1;i<=m;i++){
		long long sum=0;
		for (int j=1;j<=*q;j++)
			if (i>=q[j]) sum+=1ll*f[i-q[j]]*s[q[j]];
		f[i]=sum%mo;
	}
	cout<<f[m]<<endl;
}