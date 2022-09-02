#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline char getc(){static char buf[1<<20],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getc()))f^=!(c^45);x=(c&15);while(isdigit(c=getc()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005;
int n,Q,a[N];
vector<int>v[N];
int count(int l,int r,int x){
	return upper_bound(v[x].begin(),v[x].end(),r)-lower_bound(v[x].begin(),v[x].end(),l);
}
struct node{
	int x[6],y[6],l;
	void ps(int x_,int y_){
		rep(i,0,l-1)if(x[i]==x_){
			y[i]+=y_;
			return;
		}
		if(l<6){
			x[l]=x_;
			y[l]=y_;
			++l;
		}else{
			int pos=min_element(y,y+l)-y;
			if(y_>y[pos]){
				int t=y[pos];
				rep(i,0,l-1){
					y[i]-=t;
				}
				y_-=t;
				x[pos]=x_;
				y[pos]=y_;
			}else{
				rep(i,0,l-1)y[i]-=y_;
			}
		}
	}
	node operator+(const node&rhs)const{
		node res;
		res=*this;
		rep(i,0,rhs.l-1){
			res.ps(rhs.x[i],rhs.y[i]);
		}
		return res;
	}
}t[N*4];
void upd(int k1){
	t[k1]=t[k1*2]+t[k1*2+1];
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		t[k1].l=1;
		t[k1].x[0]=a[k2];
		t[k1].y[0]=1;
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
node qry(int k1,int k2,int k3,int k4,int k5){
	if(k2==k4&&k3==k5){
		return t[k1];
	}
	int mid=(k2+k3)>>1;
	if(k5<=mid)return qry(k1*2,k2,mid,k4,k5);
	else if(mid+1<=k4)return qry(k1*2+1,mid+1,k3,k4,k5);
	else return qry(k1*2,k2,mid,k4,mid)+qry(k1*2+1,mid+1,k3,mid+1,k5);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(Q);
	rep(i,1,n)rd(a[i]),v[a[i]].pb(i);
	bud(1,1,n);
	while(Q--){
		int l,r,k;
		rd(l),rd(r),rd(k);
		node cur=qry(1,1,n,l,r);
		int ans=-1;
		rep(i,0,cur.l-1){
			if(1LL*count(l,r,cur.x[i])*k>(r-l+1)){
				if(ans==-1)ans=cur.x[i];
				else ans=min(ans,cur.x[i]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}