#include <bits/stdc++.h>
using namespace std;
const int N=300050;
int n,q,a[N],ans[N],l[N],r[N];
vector<pair<int,int>> Qs[N];
struct RMQ{
	int mn[2*N];
	RMQ(){}
	void init(){
		for(int i=0;i<2*N;i++)mn[i]=1e9;
	}
	void Set(int c,int ss,int se,int qs,int qe,int x){
		if(ss>se||ss>qe||se<qs)return;
		if(qs<=ss&&se<=qe){mn[c]=min(mn[c],x);return;}
		int mid=ss+se>>1;
		Set(c<<1,ss,mid,qs,qe,x);
		Set(c<<1|1,mid+1,se,qs,qe,x);
	}
	int Get(int c,int ss,int se,int qi){
		if(ss==se)return mn[c];
		int mid=ss+se>>1;
		if(qi<=mid)return min(mn[c],Get(c<<1,ss,mid,qi));
		else return min(mn[c],Get(c<<1|1,mid+1,se,qi));
	}
};
const int M=20*N;
struct SegTree{
	int root,tsz,ls[M],rs[M],mx[M];
	SegTree(){}
	void init(){
		root=tsz=0;
		for(int i=0;i<M;i++)mx[i]=-1,ls[i]=rs[i]=0;
	}
	void Set(int&c,int ss,int se,int qi,int x){
		if(!c)c=++tsz;
		mx[c]=max(mx[c],x);
		if(ss==se)return;
		int mid=ss+se>>1;
		if(qi<=mid)Set(ls[c],ss,mid,qi,x);
		else Set(rs[c],mid+1,se,qi,x);
	}
	int Get(int c,int ss,int se,int qs,int qe){
		if(!c||ss>qe||se<qs||ss>se)return -1;
		if(qs<=ss&&se<=qe)return mx[c];
		int mid=ss+se>>1;
		return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
	}
};
int main(){
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	scanf("%i",&q);
	for(int i=1;i<=q;i++)scanf("%i%i",&l[i],&r[i]),ans[i]=1e9;
	for(int rep=1;rep<=2;rep++){
		for(int i=1;i<=n;i++)Qs[i].clear();
		RMQ Q; Q.init();
		for(int i=1;i<=q;i++)Qs[r[i]].push_back({l[i],i});
		SegTree ST; ST.init();
		for(int i=1;i<=n;i++){
			int x=1e9;
			while(x>=a[i]){
				int j=ST.Get(ST.root,1,1e9,a[i],x);
				if(j==-1)break;
				Q.Set(1,1,n,1,j,a[j]-a[i]);
				x=min(a[j]-1,(a[i]+a[j])>>1);
			}
			for(auto p:Qs[i])ans[p.second]=min(ans[p.second],Q.Get(1,1,n,p.first));
			ST.Set(ST.root,1,1e9,a[i],i);
		}
		reverse(a+1,a+1+n);
		for(int i=1;i<=q;i++)l[i]=n-l[i]+1,r[i]=n-r[i]+1,swap(l[i],r[i]);
	}
	for(int i=1;i<=q;i++)printf("%i ",ans[i]);
	return 0;
}