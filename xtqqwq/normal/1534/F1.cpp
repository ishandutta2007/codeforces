#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,cnt,ncnt,scnt,tot;
int v[1600005],nxt[1600005],h[400005],dfn[400005],low[400005],col[400005],q[400005],du[400005],lf[400005],rg[400005],a[400005],lg2[400005],rmq[400005][20],d[400005];
vector<int> adj[400005];
set<int> st[400005];
vector<vector<int> > lab;
vector<vector<char> > s;
char str[400005];
bool ins[400005],tfl[400005];
stack<int> stk;

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

void tarjan(int u){
	dfn[u]=low[u]=++ncnt;
	stk.push(u); ins[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(!dfn[v[p]]) tarjan(v[p]),chkmin(low[u],low[v[p]]);
		else if(ins[v[p]]) chkmin(low[u],dfn[v[p]]);
	}
	if(dfn[u]==low[u]){
		int tmp;
		scnt++;
		do{
			tmp=stk.top(); stk.pop();
			col[tmp]=scnt,ins[tmp]=0;
		}while(tmp!=u);
	}
}

int getmin(int l,int r){
	if(l>r) return 1<<30;
	int k=lg2[r-l+1];
	return min(rmq[r][k],rmq[l+(1<<k)-1][k]);
}

int main(){
	n=readint(); m=readint();
	s.resize(n+1),lab.resize(n+1);
	for(int i=1;i<=n;i++) s[i].resize(m+1),lab[i].resize(m+1);
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		for(int j=1;j<=m;j++) s[i][j]=str[j];
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='#') lab[i][j]=++cnt;
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) if(s[j][i]=='#') st[i].insert(j);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]!='#') continue;
			if(j>1){
				auto it=st[j-1].lower_bound(i);
				if(it!=st[j-1].end()) addedge(lab[i][j],lab[*it][j-1]);
			}
			if(j<m){
				auto it=st[j+1].lower_bound(i);
				if(it!=st[j+1].end()) addedge(lab[i][j],lab[*it][j+1]);
			}
			if(i>1&&s[i-1][j]=='#') addedge(lab[i][j],lab[i-1][j]);
			auto it=st[j].upper_bound(i);
			if(it!=st[j].end()) addedge(lab[i][j],lab[*it][j]);
		}
	}
	for(int i=1;i<=cnt;i++) if(!dfn[i]) tarjan(i);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout<<col[lab[i][j]]<<' ';
//		cout<<endl;
//	}
	for(int i=1;i<=cnt;i++)
		for(int p=h[i];p;p=nxt[p])
			if(col[i]!=col[v[p]]) du[col[v[p]]]++,adj[col[i]].pb(col[v[p]]);
	vector<int> vec(0);
	int front=0,rear=0;
	for(int i=1;i<=scnt;i++) if(!du[i]) q[rear++]=i,vec.pb(i);
	printf("%d\n",vec.size());
	return 0;
	while(front<rear){
		int t=q[front++];
		for(auto v:adj[t]) if(!(--du[v])) q[rear++]=v;
	}
//	for(int i=0;i<rear;i++) cout<<q[i]<<' ';
//	cout<<endl;
	for(int i=1;i<=m;i++) a[i]=readint();
	for(int i=1;i<=scnt;i++) lf[i]=m+1,rg[i]=0;
	for(int i=1;i<=m;i++){
		if(!a[i]){
			tfl[i]=1;
			continue;
		}
		for(int j=n;j>=1;j--){
			if(s[j][i]=='#'){
				a[i]--;
				if(!a[i]){
					chkmin(lf[col[lab[j][i]]],i);
					chkmax(rg[col[lab[j][i]]],i);
					break;
				}
			}
		}
	}
	for(int i=rear-1;i>=0;i--){
		for(auto v:adj[q[i]]){
			chkmin(lf[q[i]],lf[v]);
			chkmax(rg[q[i]],rg[v]);
		}
	}
	vector<pii> pr(0);
	for(auto r:vec) pr.pb(mp(rg[r],lf[r]));
	int tcnt=0;
	for(int i=1;i<=m;i++) if(st[i].size()==0||tfl[i]) pr.pb(mp(i,i)),tcnt++;
	sort(pr.begin(),pr.end());
//	for(auto r:pr) cout<<r.fi<<' '<<r.se<<endl;
	for(int i=2;i<=m;i++) lg2[i]=lg2[i>>1]+1;
	int ans=1<<30;
	for(int i=0;i<pr.size();i++){
		pii r=pr[i];
		if(r.se==1) d[i]=1;
		else{
			int pl=lower_bound(pr.begin(),pr.end(),mp(r.se-1,0))-pr.begin();
			d[i]=getmin(pl,i-1)+1;
		}
		rmq[i][0]=d[i];
		for(int j=1;(1<<j)<=i+1;j++) rmq[i][j]=min(rmq[i][j-1],rmq[i-(1<<(j-1))][j-1]);
		if(r.fi==m) chkmin(ans,d[i]);
	}
	printf("%d\n",ans-tcnt);
	return 0;
}