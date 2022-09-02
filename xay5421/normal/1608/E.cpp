#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
template<class T>void umax(T&x,const T&y){if(x<y)x=y;}
const int N=100005;
int n,ans;
struct node{
	int x,y,c;
}a[N],b[N];
void turn(){
	rep(i,1,n){
		a[i]=(node){-a[i].y,a[i].x,a[i].c};
	}
}
void sol1(const array<int,3>&p){
	int l=ans+1,r=n/3;
	auto chk=[&](int mid){
		int pos=1;
		rep(i,0,2){
			int cnt=0;
			while(pos<=n&&cnt<mid){
				cnt+=a[pos].c==p[i];
				++pos;
			}
			while(pos<=n&&pos>1&&a[pos].x==a[pos-1].x)++pos;
			if(i==2){
				return cnt>=mid;
			}
		}
		assert(0);
	};
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid)){
			umax(ans,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
}
void sol2(const array<int,3>&p){
	int m=0;
	rep(i,1,n)if(a[i].c==p[0]){
		b[++m]=a[i];
	}
	int l=ans+1,r=min(n/3,m);
	auto chk=[&](int mid,int lim_y){
		int pos=1;
		rep(i,1,2){
			int cnt=0;
			while(pos<=n&&cnt<mid){
				if(a[pos].y>lim_y)cnt+=a[pos].c==p[i];
				++pos;
			}
			while(pos<=n&&pos>1&&a[pos].x==a[pos-1].x)++pos;
			if(i==2){
				return cnt>=mid;
			}
		}
		assert(0);
	};
	while(l<=r){
		int mid=(l+r)>>1;
		nth_element(b+1,b+mid,b+1+m,[&](auto&lhs,auto&rhs){
			return lhs.y<rhs.y;
		});
		int lim_y=b[mid].y; // >lim_y
		if(chk(mid,lim_y)){
			umax(ans,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
	rep(_,1,4){
		sort(a+1,a+1+n,[&](auto&lhs,auto&rhs){return lhs.x<rhs.x;});
		array<int,3>p={1,2,3};
		do{
			if(_<=2)sol1(p);
			sol2(p);
		}while(next_permutation(p.begin(),p.end()));
		turn();
	}
	printf("%d\n",ans*3);
	return 0;
}