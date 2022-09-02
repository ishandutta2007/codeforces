#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=200005;
int n;
tuple<int,int,int>v[N];
struct ufs{
	int fa[N],dis[N];
	ufs(){
		rep(i,1,N-1)fa[i]=i,dis[i]=0;
	}
	int fd(int k1){
		if(k1!=fa[k1]){
			int k2=fa[k1];
			fa[k1]=fd(fa[k1]);
			dis[k1]^=dis[k2];
		}
		return fa[k1];
	}
	void mer(int k1,int k2,int k3){
		int k1_=fd(k1),k2_=fd(k2);
		if(k1_!=k2_){
			fa[k1_]=k2_;
			dis[k1_]=dis[k1]^dis[k2]^k3;
		}else{
			if((dis[k1]^dis[k2])!=k3){
				//throw 0;
			}
		}
	}
}o;
bool chk(int x,int y){return 1LL*x*x+1LL*y*y<=1000000000000LL;}
bool good(int x,int y){return 1LL*x*x+1LL*y*y<=1500000LL*1500000LL;}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	vector<tuple<int,int,int> >vec;
	rep(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		v[i]={x,y,i};
		if(y<0){
			x=-x,y=-y;
			o.mer(i,i+n,1);
		}else{
			o.mer(i,i+n,0);
		}
		if(vec.empty()){
			vec.eb(x,y,i+n);
		}else{
			bool flg=0;
			for(auto&_:vec){
				int x_,y_,id;
				tie(x_,y_,id)=_;
				if(chk(x+x_,y+y_)){
					o.mer(i+n,id,0);
					_={x+x_,y+y_,i+n};
					flg=1;
					break;
				}else if(chk(x-x_,y-y_)){
					o.mer(i+n,id,1);
					_={x-x_,y-y_,i+n};
					flg=1;
					break;
				}
			}
			if(!flg){
				assert(SZ(vec)<=1);
				vec.eb(x,y,i+n);
			}else{
				if(SZ(vec)==2){
					if(chk(get<0>(vec[0])+get<0>(vec[1]),get<1>(vec[0])+get<1>(vec[1]))){
						o.mer(get<2>(vec[0]),get<2>(vec[1]),0);
						get<0>(vec[0])+=get<0>(vec[1]),get<1>(vec[0])+=get<1>(vec[1]);
						vec.pop_back();
					}else if(chk(get<0>(vec[0])-get<0>(vec[1]),get<1>(vec[0])-get<1>(vec[1]))){
						o.mer(get<2>(vec[0]),get<2>(vec[1]),1);
						get<0>(vec[0])-=get<0>(vec[1]),get<1>(vec[0])-=get<1>(vec[1]);
						vec.pop_back();
					}
				}
			}
		}
	}
	if(SZ(vec)==2){
		if(good(get<0>(vec[0])+get<0>(vec[1]),get<1>(vec[0])+get<1>(vec[1]))){
			o.mer(get<2>(vec[0]),get<2>(vec[1]),0);
			get<0>(vec[0])+=get<0>(vec[1]),get<1>(vec[0])+=get<1>(vec[1]);
			vec.pop_back();
		}else if(good(get<0>(vec[0])-get<0>(vec[1]),get<1>(vec[0])-get<1>(vec[1]))){
			o.mer(get<2>(vec[0]),get<2>(vec[1]),1);
			get<0>(vec[0])-=get<0>(vec[1]),get<1>(vec[0])-=get<1>(vec[1]);
			vec.pop_back();
		}
	}
	LL s1=0,s2=0;
	rep(i,1,n){
		o.fd(i);
		int res=o.dis[i]?1:-1;
		printf("%d ",res);
		s1+=res*get<0>(v[i]),s2+=res*get<1>(v[i]);
	};
	return 0;
}