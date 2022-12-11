#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e5+1;
int n;
struct Node_t {
	int l,r,tp,val,tim;
	inline bool operator<(const Node_t &o)const{return l<o.l;}
};
set<Node_t>odt;
void split(int x) {
	if(x>n)return;
	auto it=--odt.upper_bound(Node_t{x,0,0,0,0});
	if(it->l==x)return;
	int l=it->l,r=it->r,tp=it->tp,val=it->val,tim=it->tim;
	odt.erase(it);
	odt.insert(Node_t{l,x-1,tp,val,tim});
	odt.insert(Node_t{x,r,tp,val,tim});
}
struct Persistence_Segment_Tree{
	struct node{
		int l,r;
		long long val;
		node(){l=r=val=0;}
	};
	node t[N<<6];
	int root[N],tot=0;
	Persistence_Segment_Tree(){memset(root,0,sizeof root);tot=0;}
	void build(int &rt,int l,int r){
		if(!rt)rt=++tot;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(t[rt].l,l,mid);
		build(t[rt].r,mid+1,r);
	}
	void upd(int &rt,int ort,int l,int r,int x,int d){
		if(!rt)rt=++tot;
		t[rt]=t[ort];
		t[rt].val+=d;
		if(l==r)return;
		int mid=(l+r)>>1;
		if(x<=mid)upd(t[rt].l=0,t[ort].l,l,mid,x,d);
		else upd(t[rt].r=0,t[ort].r,mid+1,r,x,d);
	}
	long long query(int lrt,int rrt,int l,int r,int L,int R){
		if(L>R)return 0;
		if(L<=l&&r<=R)return t[rrt].val-t[lrt].val;
		int mid=(l+r)>>1;
		long long res=0;
		if(L<=mid)res+=query(t[lrt].l,t[rrt].l,l,mid,L,R);
		if(R>mid)res+=query(t[lrt].r,t[rrt].r,mid+1,r,L,R);
		return res;
	}
}tr1,tr2;
int s[N],m[N],r[N];
int main(){
	scanf("%d",&n);
	tr1.build(tr1.root[0],0,M);
	tr2.build(tr2.root[0],0,M);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&s[i],&m[i],&r[i]);
		if(r[i]){
			long long tim=(m[i]+r[i]-1)/r[i];
			tr1.upd(tr1.root[i],tr1.root[i-1],0,M,tim,m[i]);
			tr2.upd(tr2.root[i],tr2.root[i-1],0,M,tim,r[i]);
		}
		else{
			tr1.upd(tr1.root[i],tr1.root[i-1],0,M,M,m[i]);
			tr2.upd(tr2.root[i],tr2.root[i-1],0,M,M,r[i]);
		}
		odt.insert({i,i,0,s[i],0});
	}
	long long mm;
	scanf("%lld",&mm);
	while(mm--){
		long long tim;
		int lx,rx;
		long long ans=0;
		scanf("%lld%d%d",&tim,&lx,&rx);
		split(rx+1);split(lx);
		while(odt.lower_bound({lx})!=odt.end()&&odt.lower_bound({lx})->l<=rx){
			auto it=odt.lower_bound({lx});
			if(it->tp==0){
				long long res=it->val+1ll*r[it->l]*(tim-(it->tim));
				res=min(res,m[it->l]*1ll);
				ans+=res;
			}
			else{
				long long ct=min((M-1)*1ll,tim-it->tim);
				long long sum1=tr1.query(tr1.root[it->l-1],tr1.root[it->r],0,M,0,ct);
				long long sum2=tr2.query(tr2.root[it->l-1],tr2.root[it->r],0,M,ct+1,M);
				ans+=sum1+sum2*ct;
			}
			odt.erase(it);
		}
		printf("%lld\n",ans);
		odt.insert({lx,rx,1,0,(int)tim});
	}
	return  0;
}