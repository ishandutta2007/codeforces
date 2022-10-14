#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
const int M=N*2;
const ll inf=1e18;
ll a[N],st[M],lzy[M];
int ls[M],rs[M],tsz,root;

ll Calc(int c){return st[c]+lzy[c];}

void Build(int&c,int ss,int se){
	c=++tsz,lzy[c]=0LL;
	if(ss>se){st[c]=inf;return;}
	if(ss==se){st[c]=a[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	st[c]=min(st[ls[c]],st[rs[c]]);
}

void Set(int c,int ss,int se,int qs,int qe,int val){
	if(ss>se||ss>qe||se<qs)return;
	if(qs<=ss&&se<=qe){
		lzy[c]+=val;
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
	st[c]=min(Calc(ls[c]),Calc(rs[c]));
}

ll Get(int c,int ss,int se,int qs,int qe){
	if(ss>se||ss>qe||se<qs)return inf;
	if(qs<=ss&&se<=qe)return Calc(c);
	int mid=(ss+se)/2;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe))+lzy[c];
}

int main(){
	int n;scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	Build(root,1,n);
	int q;scanf("%i",&q);
	while(q--){
		int l,r;scanf("%i%i",&l,&r);
		l++,r++;
		char t;scanf("%c",&t);
		if(t=='\n'){
			if(l>r)printf("%lld\n",min(Get(root,1,n,l,n),Get(root,1,n,1,r)));
			else printf("%lld\n",Get(root,1,n,l,r));
		}else{
			int k;scanf("%i",&k);
			if(l>r)Set(root,1,n,l,n,k),Set(root,1,n,1,r,k);
			else Set(root,1,n,l,r,k);
		}
	}
	return 0;
}