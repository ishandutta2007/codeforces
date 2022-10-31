#include <bits/stdc++.h>

using namespace std;
typedef long long lli;
typedef pair<int,int> ip;

const int MAX=1<<18;
int uu[500001],vv[500001],cc[500001];
int n,q,pc[200001],ll[200001],rr[200001],dfn;
lli tr[1<<19],lt[1<<19];
vector<ip> adj[200001]; 

void PUSH(int node) {
	if(lt[node]==0) return;
	tr[node]+=lt[node];
	if(node<MAX) {
		int nx=node<<1;
		lt[nx]+=lt[node];
		lt[nx+1]+=lt[node];
	}
	lt[node]=0;
}
lli update(int node,int st,int fi,int le,int ri,lli val) {
	PUSH(node);
	if(fi<le||st>ri) return tr[node];
	if(le<=st&&fi<=ri) {
		lt[node]+=val;
		PUSH(node);
		return tr[node];
	}	
	else {
		int md=(st+fi)>>1,nx=node<<1;
		return tr[node]=min(update(nx,st,md,le,ri,val),update(nx+1,md+1,fi,le,ri,val));
	}
}
lli MV(int node,int st,int fi,int le,int ri) {
	PUSH(node);
	if(fi<le||st>ri) return 1e15;
	else if(le<=st&&fi<=ri) return tr[node];
	else {
		int md=(st+fi)>>1,nx=node<<1;
		return min(MV(nx,st,md,le,ri),MV(nx+1,md+1,fi,le,ri));
	}
}
void DFS(int node,lli cost) {
	update(1,0,MAX-1,dfn,dfn,cost+pc[node]);
	ll[node]=dfn++;
	for(auto &it:adj[node]) {
		DFS(it.second,cost+it.first);
	}
	rr[node]=dfn-1;
}
bool Ischild(int n1,int n2) {
	return (ll[n1]<=ll[n2]&&rr[n2]<=rr[n1]) ;
}
int main() {
	int a,b,c;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n+n-2;i++) {
		scanf("%d%d%d",uu+i,vv+i,cc+i);
		a=uu[i];b=vv[i];c=cc[i];
		if(b==1) pc[a]=c;
		else adj[a].push_back(ip(c,b));
	}
	DFS(1,0);
	
	while(q--) {
		scanf("%d%d%d",&a,&b,&c);
		if(a==1) {
			b--;
			if(vv[b]==1) {
				update(1,0,MAX-1,ll[uu[b]],ll[uu[b]],c-pc[uu[b]]);
				pc[uu[b]]=c;
			}
			else {
				update(1,0,MAX-1,ll[vv[b]],rr[vv[b]],c-cc[b]);
				cc[b]=c;
			}
		}
		else {
			long long sum=0;
			if(Ischild(b,c)) {
				sum=MV(1,0,MAX-1,ll[c],ll[c])-pc[c]-MV(1,0,MAX-1,ll[b],ll[b])+pc[b];
			}
			else if(b!=c){
				if(b!=1) 
					sum+=MV(1,0,MAX-1,ll[b],rr[b])-MV(1,0,MAX-1,ll[b],ll[b])+pc[b];
				if(c!=1) 
					sum+=MV(1,0,MAX-1,ll[c],ll[c])-pc[c];
			}
			printf("%lld\n",sum);
		}
	}
	
	return 0;
}