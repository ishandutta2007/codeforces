#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int M=2*N;
int n,q,a[N],root,tsz,ls[M],rs[M];
vector<int> st[M];
vector<int> mrg(vector<int> x,vector<int> y){
	vector<int> ret;
	int i=0,j=0;
	while((i<x.size()||j<y.size())&&ret.size()<=30){
		if(j==y.size()||(i<x.size()&&x[i]<y[j]))ret.push_back(x[i++]);
		else ret.push_back(y[j++]);
	}
	return ret;
}
void Build(int&c,int ss,int se){
	c=++tsz;
	if(ss==se){st[c]={a[ss]};return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	st[c]=mrg(st[ls[c]],st[rs[c]]);
}
vector<int> Get(int c,int ss,int se,int qs,int qe){
	if(ss>se||ss>qe||se<qs)return {};
	if(qs<=ss&&se<=qe)return st[c];
	int mid=ss+se>>1;
	return mrg(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	tsz=0;Build(root,1,n);
	scanf("%d",&q);
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		vector<int> vec=Get(root,1,n,l,r);
		int ans=(1<<30);
		for(int i=0;i<vec.size();i++)for(int j=i+1;j<vec.size();j++)ans=min(ans,vec[i]|vec[j]);
		printf("%d\n",ans);
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)solve();
	return 0;
}