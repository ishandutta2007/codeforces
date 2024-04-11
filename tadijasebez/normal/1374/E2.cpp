#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200050;
const int M=2*N;
int ls[M],rs[M],tsz,sz[M],sum[M],root;
void Add(int&c,int ss,int se,int qi,int f,int x){
	if(!c)c=++tsz;
	sz[c]+=f;
	sum[c]+=x;
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Add(ls[c],ss,mid,qi,f,x);
	else Add(rs[c],mid+1,se,qi,f,x);
}
int Get(int c,int ss,int se,int k){
	if(ss==se)return k?sum[c]:0;
	int mid=ss+se>>1;
	if(sz[ls[c]]>=k)return Get(ls[c],ss,mid,k);
	else return Get(rs[c],mid+1,se,k-sz[ls[c]])+sum[ls[c]];
}
int t[N],a[N],b[N],idx[N],ord[N],now;
void Add(int i){
	Add(root,1,N,idx[i],1,t[i]);
}
void Del(int i){
	Add(root,1,N,idx[i],-1,-t[i]);
}
int Get(int k){
	return Get(root,1,N,k);
}
int main(){
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	vector<int> AB,A,B;
	for(int i=1;i<=n;i++){
		scanf("%i %i %i",&t[i],&a[i],&b[i]);
		ord[i]=i;
		if(a[i]&&b[i])AB.pb(i);
		else if(a[i])A.pb(i);
		else if(b[i])B.pb(i);
	}
	sort(ord+1,ord+1+n,[&](int i,int j){return t[i]<t[j];});
	sort(AB.begin(),AB.end(),[&](int i,int j){return t[i]<t[j];});
	sort(A.begin(),A.end(),[&](int i,int j){return t[i]<t[j];});
	sort(B.begin(),B.end(),[&](int i,int j){return t[i]<t[j];});
	for(int i=1;i<=n;i++)idx[ord[i]]=i;
	int top=min(k,(int)AB.size()),bot=max(0,k-(int)min(A.size(),B.size()));
	for(int i=1;i<=n;i++)Add(i);
	int ans=-1,qbz;
	auto cns=[&](int x,int y){
		if(ans==-1||ans>x)ans=x,qbz=y;
	};
	if(top>=bot){
		for(int i=0;i<bot;i++)Del(AB[i]),now+=t[AB[i]];
		for(int i=0;i<k-bot;i++)Del(A[i]),Del(B[i]),now+=t[A[i]]+t[B[i]];
		for(int i=bot;i<=top;i++){
			int uk=i+2*(k-i);
			if(uk<=m){
				cns(Get(m-uk)+now,i);
			}
			if(i!=top){
				Del(AB[i]);
				Add(A[k-i-1]);
				Add(B[k-i-1]);
				now+=t[AB[i]]-t[A[k-i-1]]-t[B[k-i-1]];
			}
		}
	}
	printf("%i\n",ans);
	if(ans!=-1){
		vector<int> sol;
		vector<bool> was(n+1,false);
		for(int i=0;i<qbz;i++)sol.pb(AB[i]);
		for(int i=0;i<k-qbz;i++)sol.pb(A[i]),sol.pb(B[i]);
		int uk=m-sol.size();
		for(int i:sol)was[i]=true;
		vector<int> ost;
		for(int i=1;i<=n;i++)if(!was[i])ost.pb(i);
		sort(ost.begin(),ost.end(),[&](int i,int j){return t[i]<t[j];});
		for(int i=0;i<uk;i++)sol.pb(ost[i]);
		sort(sol.begin(),sol.end());
		for(int i:sol)printf("%i ",i);
	}
	return 0;
}