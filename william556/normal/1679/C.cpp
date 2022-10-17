#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;	
}
const int N=1e5+5;
int n,q;
struct seg{
	int val[N<<2];
	void add(int p,int l,int r,int d,int v){
		if(l==r){
			val[p]+=v;
			return;
		}
		int mid=l+r>>1;
		if(d<=mid)add(p<<1,l,mid,d,v);
		else add(p<<1|1,mid+1,r,d,v);
		val[p]=min(val[p<<1],val[p<<1|1]);;
	}
	int query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return val[p];
		int mid=l+r>>1,mn=n+1;
		if(ql<=mid)mn=min(mn,query(p<<1,l,mid,ql,qr));
		if(mid<qr)mn=min(mn,query(p<<1|1,mid+1,r,ql,qr));
		return mn;	
	}
}s1,s2;
int main(){
	n=in(),q=in();
	while(q--){
		int opt=in(),x=in(),y=in();
		if(opt==1){
			s1.add(1,1,n,x,1);
			s2.add(1,1,n,y,1);
		}
		if(opt==2){
			s1.add(1,1,n,x,-1);
			s2.add(1,1,n,y,-1);
		}
		if(opt==3){
			int xx=in(),yy=in();;
			int res1=s1.query(1,1,n,x,xx);
			int res2=s2.query(1,1,n,y,yy);
			if(res1||res2)puts("Yes");
			else puts("No");
		}
	}
	return 0;
}