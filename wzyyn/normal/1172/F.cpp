#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const ll INF=1ll<<60;
const int N=1000005;
struct line{
	ll l,r,d;
};
vector<line> t[1<<21];
int n,p,Q,a[N];
void pushup(int k){
	/*For(T,1,10)
		printf("merge %d\n",k);*/
	int sz1=t[k*2].size();
	int sz2=t[k*2+1].size();
	int p1=0,p2=0,tp=-1;
	line l1=t[k*2][0];
	for (;;){
		ll l=max(-INF,l1.l+l1.d);
		ll r=min(INF,l1.r+l1.d);
		for (;l>r;){
			if ((++p1)==sz1) break;
			l1=t[k*2][p1];
			l=max(-INF,l1.l+l1.d);
			r=min(INF,l1.r+l1.d);
		}
		if (p1==sz1) break;
		for (;l<t[k*2+1][p2].l;--p2);
		for (;l>t[k*2+1][p2].r;++p2);
		/*puts("info_ST");
		printf("%d %d %d %d\n",p1,p2,sz1,sz2);
		l1.out(); t[k*2+1][p2].out();
		printf("%lld %lld\n",l,r);
		printf("%d %d\n",p1,p2);*/
		if (r<t[k*2+1][p2].r){
			t[k].PB((line){l1.l,l1.r,l1.d+t[k*2+1][p2].d}); ++tp;
			if (tp&&t[k][tp].d==t[k][tp-1].d){
				t[k][tp-1].r=t[k][tp].r;
				tp--; t[k].pop_back();
			}
			if ((++p1)==sz1) break;
			l1=t[k*2][p1];
		}
		else{
			t[k].PB((line){l1.l,t[k*2+1][p2].r-l1.d,l1.d+t[k*2+1][p2].d}); ++tp;
			if (tp&&t[k][tp].d==t[k][tp-1].d){
				t[k][tp-1].r=t[k][tp].r;
				tp--; t[k].pop_back();
			}
			l1.l=t[k*2+1][p2].r-l1.d+1;
			//printf("%lld %lld\n",t[k*2+1][p2].r,l1.d);
			if (l1.r<l1.l){
				if ((++p1)==sz1) break;
				l1=t[k*2][p1];
			}
		}
	}
	For(i,0,t[k].size()-1){
		if (t[k][i].l<-INF/2) t[k][i].l=-INF;
		if (t[k][i].r>INF/2) t[k][i].r=INF;
	}
}
void build(int k,int l,int r){
	if (l==r){
		t[k].PB((line){-INF,p-1-a[l],a[l]});
		t[k].PB((line){p-a[l],INF,a[l]-p});
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
ll ask(int k,int l,int r,int x,int y,ll val){
	//printf("%d %d %d %d %d %lld\n",k,l,r,x,y,val);
	if (x<=l&&r<=y){
		int L=0,R=t[k].size()-1,p=0;
		while (L<=R){
			int mid=(L+R)/2;
			if (t[k][mid].r>=val)
				p=mid,R=mid-1;
			else L=mid+1;
		}
		return val+t[k][p].d;
	}
	int mid=(l+r)/2;
	if (x<=mid) val=ask(k*2,l,mid,x,y,val);
	if (y>mid) val=ask(k*2+1,mid+1,r,x,y,val);
	return val;
}
int main(){
	scanf("%d%d%d",&n,&Q,&p);
	For(i,1,n) scanf("%d",&a[i]);
	build(1,1,n);
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",ask(1,1,n,l,r,0)); 
	}
}