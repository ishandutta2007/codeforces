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
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=1005;
int w,h,n;
struct vec{
	long double x,y;
	vec(){}
	vec(long double x,long double y):x(x),y(y){}
	bool operator<(const vec&rhs)const{
		return 0;
	}
	vec operator-(const vec&rhs)const{return vec(x-rhs.x,y-rhs.y);}
	long double len()const{return sqrt(1LL*x*x+1LL*y*y);}
}p[N];
int q0;
long long cross(const vec&lhs,const vec&rhs){
	return 1LL*lhs.x*rhs.y-1LL*lhs.y*rhs.x;
}
long double calc(vec cur){
	long double mn[2]={1e100,1e100};
	rep(i,1,n){
		long double now=(cur-p[i]).len();
		if(now<mn[0]){
			mn[1]=mn[0],mn[0]=now;
		}else if(now<mn[1]){
			mn[1]=now;
		}
	}
	return mn[1];
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	cin>>w>>h>>n;
	rep(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		p[i]=vec(x,y);
	}
	long double k=0.1;
	vector<pair<long double,vec> >v;
	rep(i,0,9){
		rep(j,0,9){
			vec now(w*i*k,h*j*k);
			v.eb(calc(now),now);
		}
	}
	int tc=10;
	while(tc--){
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		//D("%d\n",SZ(v));
		if(SZ(v)>100)v.resize(100);
		k*=0.1;
		vector<pair<long double,vec> >new_v;
		rep(_,0,SZ(v)-1){
			vec cur=get<1>(v[_]);
			rep(i,0,9)rep(j,0,9){
				vec nex(cur.x+w*i*k,cur.y+h*j*k);
				new_v.eb(calc(nex),nex);
			}
		}
		v.insert(v.end(),new_v.begin(),new_v.end());
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	printf("%.20f\n",(double)get<0>(v[0]));
	return 0;
}