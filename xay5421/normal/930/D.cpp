#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>bool umin(T&x,const T&y){return y<x?x=y,1:0;}
template<class T>bool umax(T&x,const T&y){return x<y?x=y,1:0;}
const int N=100005,INF=0X3F3F3F3F;
int n_,n,mn[N],mx[N],minx[N],maxx[N],ll[N],rr[N];
long long ans;
struct node{
	int x,y;
	bool operator<(const node&k)const{
		return x<k.x;
	}
}p_[N],p[N];
void sol(){
	sort(p+1,p+n+1);
	mn[0]=INF,mx[0]=~INF;
	rep(i,1,n){
		mn[i]=mn[i-1];
		mx[i]=mx[i-1];
		umin(mn[i],p[i].y);
		umax(mx[i],p[i].y);
	}
	minx[n+1]=INF,maxx[n+1]=~INF;
	per(i,n,1){
		minx[i]=minx[i+1];
		maxx[i]=maxx[i+1];
		umin(minx[i],p[i].y);
		umax(maxx[i],p[i].y);
	}
	/*ll[1]=0;
	rep(i,2,n){
		ll[i]=p[i].x==p[i-1].x?ll[i-1]:i-1;
	}
	rr[n]=n+1;
	per(i,n-1,1){
		rr[i]=p[i].x==p[i+1].x?rr[i+1]:i+1;
	}*/
	rep(i,1,n)ll[i]=i,rr[i]=i;
	rep(i,1,n-1)if(p[i].x<p[i+1].x){
		int lb=max(mn[ll[i]],minx[rr[i+1]])+1;
		int rb=min(mx[ll[i]],maxx[rr[i+1]])-1;
		if(lb<=rb){
			ans+=1LL*((p[i+1].x-p[i].x)/2)*((rb-lb)/2+1);
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n_);
	rep(i,1,n_)scanf("%d%d",&p_[i].x,&p_[i].y);
	rep(opt,0,1){
		n=0;
		rep(i,1,n_){
			if(((p_[i].x+p_[i].y)&1)==opt){
				p[++n]=(node){p_[i].x+p_[i].y,p_[i].x-p_[i].y};
			}
		}
		sol();
	}
	printf("%lld\n",ans);
	return 0;
}