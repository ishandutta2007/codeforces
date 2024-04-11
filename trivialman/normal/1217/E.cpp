#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int INF = 1e9;
const int N = 2e5+5;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
struct dat{
	int m1,m2;
	dat(){m1=m2=1e9;}
	dat operator+ (dat y){
	    dat z = *this;
	    if(y.m1<z.m1)
    		z.m2 = z.m1, z.m1 = y.m1;
    	else if(y.m1<z.m2)
    		z.m2 = y.m1;
    	if(y.m2<z.m2)
    		z.m2 = y.m2;
    	return z;
	}
};
 
int n,m,t,l,r,a[N];
 
struct segment_tree{
	dat a[(1<<19)+5];
	void upd(int i,int x,int l=1,int r=n,int id=1){
		if(l==r){ a[id].m1=x,a[id].m2=1e9; return; }
		int m = l+r>>1;
		if(i<=m) upd(i,x,l,m,id<<1);
		else upd(i,x,m+1,r,id<<1|1);
		a[id] = a[id<<1] + a[id<<1|1];
	}
	dat query(int l,int r,int l1=1,int r1=n,int id=1){
		if(l<=l1 && r>=r1) return a[id];
		int m1 = l1+r1>>1;
		if(r<=m1) return query(l,r,l1,m1,id<<1);
		if(l>=m1+1) return query(l,r,m1+1,r1,id<<1|1);
		return query(l,r,l1,m1,id<<1) + query(l,r,m1+1,r1,id<<1|1);
	}
}tr[10];
 
void upd1(int i,int x){
	int y = x;
	rep(j,0,9){
		if(y%10) tr[j].upd(i,x);
		else tr[j].upd(i,1e9);
		y/=10;
	}
}
int query1(int l,int r){
	int res = 2e9;
	rep(i,0,9){
		dat x = tr[i].query(l,r);
		if(x.m2==1e9)continue;
		res = min(res, x.m1+x.m2);
	}
	return res==2e9 ? -1 : res;
}
 
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",a+i);
		upd1(i,a[i]);
	}
	rep(i,1,m){
		scanf("%d%d%d",&t,&l,&r);
		if(t==1) upd1(l,r);
		else printf("%d\n",query1(l,r));
	}
	return 0;
}