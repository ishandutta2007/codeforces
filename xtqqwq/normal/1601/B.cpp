#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot;
queue<int> q1,q2;
int dis[600005],a[300005],b[300005],fr[600005],v[1000005],c[1000005],nxt[1000005],h[600005];

void addedge(int x,int y,int z){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot; c[tot]=z;
}

void bfs(int s){
	for(int i=0;i<=n+n;i++) dis[i]=1<<30;
	dis[s]=0,fr[s]=-1;
	q1.push(s);
	while(!q1.empty()||!q2.empty()){
		int t;
		if(!q2.empty()) t=q2.front(),q2.pop();
		else t=q1.front(),q1.pop();
		for(int p=h[t];p;p=nxt[p]){
			if(chkmin(dis[v[p]],dis[t]+c[p])){
				fr[v[p]]=t;
				if(!c[p]) q2.push(v[p]);
				else q1.push(v[p]);
			}
		}
	}
}

void work(int u){
	if(fr[u]>=0) work(fr[u]);
	if(!u) printf("0 ");
	else if(fr[u]>n&&u<=n) printf("%d ",fr[u]-n);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) b[i]=readint();
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			addedge(i,0,1);
			continue;
		}
		addedge(i,i-a[i]+n,1);
	}
	for(int i=1;i<n;i++) addedge(i+n,i+n+1,0);
	for(int i=1;i<=n;i++) addedge(i+n,i+b[i],0);
	bfs(n);
	if(dis[0]==(1<<30)) printf("-1\n");
	else{
		printf("%d\n",dis[0]);
		work(0);
		printf("\n");
	}
	return 0;
}