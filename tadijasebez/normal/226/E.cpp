#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int M=20*N;
int ls[M],rs[M],tsz,root[N],sum[M],n;
void Set(int p,int &c,int ss,int se,int qi){
	c=++tsz;ls[c]=ls[p];rs[c]=rs[p];sum[c]=sum[p]+1;
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[p],ls[c],ss,mid,qi);
	else Set(rs[p],rs[c],mid+1,se,qi);
}
int Sum(int p,int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return 0;
	if(qs<=ss&&qe>=se)return se-ss+1-sum[c]+sum[p];
	int mid=ss+se>>1;
	return Sum(ls[p],ls[c],ss,mid,qs,qe)+Sum(rs[p],rs[c],mid+1,se,qs,qe);
}
int GetKth(int p,int c,int ss,int se,int k){
	if(ss==se)return ss;
	int mid=ss+se>>1,sz=mid-ss+1-sum[ls[c]]+sum[ls[p]];
	if(sz>=k)return GetKth(ls[p],ls[c],ss,mid,k);
	return GetKth(rs[p],rs[c],mid+1,se,k-sz);
}
int Get(int p,int c,int qs,int qe,int k){
	if(qs<=qe)return GetKth(p,c,1,n,k+Sum(p,c,1,n,1,qs-1));
	else{
		swap(qs,qe);
		return GetKth(p,c,1,n,Sum(p,c,1,n,1,qe)-k+1);
	}
}
vector<int> E[N];
int head[N],sz[N],dep[N],lid[N],rid[N],tid,par[N],node[N];
void DFS(int u,int p){
	dep[u]=dep[p]+1;
	sz[u]=1;
	for(int v:E[u])DFS(v,u),sz[u]+=sz[v];
}
void HLD(int u){
	if(!head[u])head[u]=u;
	int hc=-1;
	lid[u]=++tid;
	node[tid]=u;
	for(int i=0;i<E[u].size();i++)if(sz[E[u][i]]*2>=sz[u])hc=i;
	if(~hc)swap(E[u][0],E[u][hc]),head[E[u][0]]=head[u];
	for(int v:E[u])HLD(v);
	rid[u]=tid;
}
int Solve(int p,int c,int u,int v,int k){
	vector<pair<int,int>> L,R;
	while(head[u]!=head[v]){
		if(dep[head[u]]>dep[head[v]])L.pb({lid[head[u]],lid[u]}),u=par[head[u]];
		else R.pb({lid[head[v]],lid[v]}),v=par[head[v]];
	}
	if(dep[u]>=dep[v])L.pb({lid[v],lid[u]});
	else R.pb({lid[u],lid[v]});
	reverse(L.begin(),L.end());
	bool fir=1;
	while(L.size()){
		pair<int,int> seg=L.back();L.pop_back();
		if(fir)seg.second--,fir=0;
		if(R.empty()&&L.empty())seg.first++;
		if(seg.first>seg.second)continue;
		int sm=Sum(p,c,1,n,seg.first,seg.second);
		if(k>sm)k-=sm;
		else return node[Get(p,c,seg.second,seg.first,k)];
	}
	while(R.size()){
		pair<int,int> seg=R.back();R.pop_back();
		if(fir)seg.first++,fir=0;
		if(R.empty()&&L.empty())seg.second--;
		if(seg.first>seg.second)continue;
		int sm=Sum(p,c,1,n,seg.first,seg.second);
		if(k>sm)k-=sm;
		else return node[Get(p,c,seg.first,seg.second,k)];
	}
	return -1;
}
int main(){
	scanf("%i",&n);
	for(int i=1,p;i<=n;i++)scanf("%i",&p),E[p].pb(i),par[i]=p;
	DFS(E[0][0],0);
	HLD(E[0][0]);
	int m;scanf("%i",&m);
	for(int i=1;i<=m;i++){
		root[i]=root[i-1];
		int t;scanf("%i",&t);
		if(t==1){
			int u;scanf("%i",&u);
			Set(root[i],root[i],1,n,lid[u]);
		}else{
			int u,v,k,y;
			scanf("%i %i %i %i",&u,&v,&k,&y);
			printf("%i\n",Solve(root[y],root[i],u,v,k));
		}
	}
	return 0;
}