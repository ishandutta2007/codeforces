#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define mid ((l+r)>>1)
#define ls a[t].l
#define rs a[t].r
const int N = 300010; 
int x,y,cnt,n,m,k,c,d,rt[N];
struct dat{int c,l,r;}a[N*30],e[N];
inline void bil(int &t,int k){a[t=++cnt]=a[k];}
void upd(int t,int l,int r){
	if (l==r) a[t].c=max(a[t].c,y);
	else{
		if (x<=mid) bil(ls,ls),upd(ls,l,mid);
		else bil(rs,rs),upd(rs,mid+1,r);
		a[t].c=min(a[ls].c,a[rs].c);
	}
}
int qry(int t,int l,int r){
	if (x<=l && r<=y) return a[t].c;
	return min(x<=mid?qry(ls,l,mid):2e9,y>mid?qry(rs,mid+1,r):2e9);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>k; 
	rep(i,1,k)cin>>e[i].l>>e[i].r>>e[i].c;
	sort(e+1,e+k+1,[](dat x,dat y){return x.r<y.r;});
	rep(i,1,k)bil(rt[i],rt[i-1]),x=e[i].c,y=e[i].l,upd(rt[i],1,n);
	while(m--){
		cin>>x>>y>>c>>d;
		int l=0,r=k+1;
		while (l<r-1) e[mid].r<=d?l=mid:r=mid;
		cout<<(qry(rt[l],1,n)>=c?"yes\n":"no\n")<<flush;
	}
}