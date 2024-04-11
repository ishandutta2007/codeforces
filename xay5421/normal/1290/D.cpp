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
const int N=1030;
int n,K,is_first[N];
#ifdef xay5421
int a[N];
int tt;
deque<int>q;
bool push(int x){
	++tt;
	x=a[x];
	int ret=1;
	each(y,q)if(x==y){
		ret=0;
	}
	q.pb(x);
	if(SZ(q)>K)q.pop_front();
	D("push(%d)=%d\n",x,ret);
	return ret;
}
void clear(){
	D("clear()\n");
	q.clear();
}
#else
bool push(int x){
	printf("? %d\n",x);
	fflush(stdout);
	char ch;
	cin>>ch;
	return ch=='N';
}
void clear(){
	puts("R"),fflush(stdout);
}
#endif
int main(){
	scanf("%d%d",&n,&K);
#ifdef xay5421
	rep(i,1,n)scanf("%d",&a[i]);
	//rep(i,1,n)a[i]=i;
#endif
	fill(is_first+1,is_first+n+1,1);
	auto ps=[&](int x){
		int l=(x-1)*K+1,r=x*K;
		//D("ps %d l=%d r=%d\n",x,l,r);
		rep(i,l,r)if(is_first[i]&&!push(i)){
			is_first[i]=0;
		}
	};
	rep(i,1,n/K){
		int dt=0;
		clear();
		rep(j,1,n/K){
			ps((i+dt-1+n/K)%(n/K)+1);
			dt=(dt<=0)-dt;
		}
	}
	int ans=0;
	rep(i,1,n)if(is_first[i])++ans;
	printf("! %d\n",ans);
	return 0;
}