#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=400005;
int n,m,Q,gap[N],fa[N];
LL sum[N],res,ans[N];
tuple<int,int>a[N];
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
struct node{
	int l,r,k;
	LL operator()(){
		return sum[r]-sum[r-k];
	}
}val[N];
void mer(node&lhs,node&rhs){
	//D("mer {%d,%d,%d} {%d,%d,%d} old_res=%lld\n",lhs.l,lhs.r,lhs.k,rhs.l,rhs.r,rhs.k,res);
	res-=lhs()+rhs();
	rhs.k+=lhs.k;
	res+=rhs();
	//D("new_res=%lld\n",res);
};
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m),rd(Q);
	rep(i,1,n)rd(get<0>(a[i])),get<1>(a[i])=1;
	rep(i,n+1,n+m)rd(get<0>(a[i])),get<1>(a[i])=0;
	sort(a+1,a+n+m+1);
	rep(i,1,n+m){
		fa[i]=i;
		sum[i]=sum[i-1]+get<0>(a[i]);
		val[i]=(node){i,i,get<1>(a[i])};
		res+=get<1>(a[i])*get<0>(a[i]);
		//D("%d ",get<0>(a[i]));
	}
	//D("\n");
	rep(i,1,n+m-1){
		gap[i]=i;
	}
	sort(gap+1,gap+n+m,[&](int lhs,int rhs){return get<0>(a[lhs+1])-get<0>(a[lhs])<get<0>(a[rhs+1])-get<0>(a[rhs]);});
	vector<tuple<int,int> >qs;
	rep(i,1,Q){
		int k;
		rd(k);
		qs.eb(k,i);
	}
	sort(qs.begin(),qs.end());
	int i=1;
	for(auto&cur:qs){
		while(i<=n+m-1&&get<0>(a[gap[i]+1])-get<0>(a[gap[i]])<=get<0>(cur)){
			assert(gap[i]==fa[gap[i]]);
			mer(val[gap[i]],val[fd(gap[i]+1)]);
			fa[gap[i]]=fd(gap[i]+1);
			++i;
		}
		ans[get<1>(cur)]=res;
	}
	rep(i,1,Q)printf("%lld\n",ans[i]);
	return 0;
}