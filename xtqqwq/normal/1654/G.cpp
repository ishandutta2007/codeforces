// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot;
int d[200005],q[200005],dis[200005],l[200005],v[400005],nxt[400005],h[200005],res[200005];
vector<int> hv[200005];
vector<pii> vec[200005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void bfs(){
	int front=0,rear=0;
	for(int i=1;i<=n;i++) d[i]=n+1;
	for(int i=1;i<=n;i++) if(l[i]) q[rear++]=i,d[i]=0;
	while(front<rear){
		int t=q[front++];
		for(int p=h[t];p;p=nxt[p]) if(chkmin(d[v[p]],d[t]+1)) q[rear++]=v[p];
	}
}

void bfs1(int i){
	int front=0,rear=0;
	for(int i=1;i<=n;i++) dis[i]=n+1;
	for(auto r:vec[i]) dis[r.fi]=dis[r.se]=0;
	for(int j=i+1;j<=n;j++){
		priority_queue<pii,vector<pii>,greater<pii> > q;
		for(auto r:hv[j]){
			for(int p=h[r];p;p=nxt[p]){
				if(d[v[p]]<d[r]) chkmin(dis[r],dis[v[p]]-1),chkmax(dis[r],0);
			}
			q.push(mp(dis[r],r));
		}
		while(!q.empty()){
			pii t=q.top(); q.pop();
			if(dis[t.se]!=t.fi) continue;
//			cout<<"??? "<<t.se<<' '<<t.fi<<endl;
			for(int p=h[t.se];p;p=nxt[p])
				if(d[v[p]]==d[t.se]&&chkmin(dis[v[p]],dis[t.se]+1))
					q.push(mp(dis[v[p]],v[p]));
		}
	}
//	cout<<"bfs "<<i<<endl;
//	for(int j=1;j<=n;j++) cout<<dis[j]<<' ';
//	cout<<endl;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) l[i]=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	bfs();
	for(int i=1;i<=n;i++) hv[d[i]].pb(i);
	for(int i=1;i<=n;i++) for(int p=h[i];p;p=nxt[p]) if(i<v[p]&&d[i]==d[v[p]]) vec[d[i]].pb(mp(i,v[p]));
	for(int j=1;j<=n;j++) res[j]=d[j];
	for(int i=0;i<=n;i++){
		if(!vec[i].size()) continue;
		bfs1(i);
		for(int j=1;j<=n;j++) if(!dis[j]) chkmin(res[j],i);
	}
	for(int i=1;i<=n;i++) printf("%d ",d[i]+d[i]-res[i]);
	printf("\n");
	return 0;
}