// author: xay5421
// created: Fri Oct  8 16:45:57 2021
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
const int N=100005;
int n,a[N];
vector<array<int,3> >ans;
void ps(int x,int y,int z){
	ans.pb({x,y,z});
	a[x]^=1,a[y]^=1,a[z]^=1;
}
int sol(int i){
	switch(a[i]*4+a[i+1]*2+a[i+2]){
		case 0:
			break;
		case 1:
			ps(i+2,i+3,i+4);
			break;
		case 2:
			ps(i+1,i+3,i+5);
			break;
		case 3:
			ps(i+1,i+2,i+3);
			break;
		case 4:
			ps(i,i+3,i+6);
			break;
		case 5:
			ps(i,i+2,i+4);
			break;
		case 6:
			switch(a[i+3]*4+a[i+4]*2+a[i+5]){
				case 0:
					ps(i,i+4,i+8);
					ps(i+1,i+4,i+7);
					break;
				case 1:
					ps(i,i+3,i+6);
					ps(i+1,i+3,i+5);
					break;
				case 2:
					ps(i,i+4,i+8);
					ps(i+1,i+6,i+11);
					break;
				case 3:
					ps(i,i+4,i+8);
					ps(i+1,i+5,i+9);
					break;
				case 4:
					ps(i,i+3,i+6);
					ps(i+1,i+6,i+11);
					break;
				case 5:
					ps(i,i+6,i+12);
					ps(i+1,i+3,i+5);
					break;
				case 6:
					ps(i,i+3,i+6);
					ps(i+1,i+4,i+7);
					break;
				case 7:
					ps(i,i+4,i+8);
					ps(i+1,i+3,i+5);
					break;
			}
			return i+6;
		case 7:
			ps(i,i+1,i+2);
			break;
	}
	return i+3;
}
void brute(int l,int r){
	vector<int>vs;
	for(int d=1;l+d+d<=r;++d){
		rep(x,l,r)if(x+d+d<=r){
			vs.pb((1<<(x-l))|(1<<(x-l+d))|(1<<(x-l+d+d)));
		}
	}
	int mask=0;
	per(i,r,l){
		mask=mask<<1|a[i];
	}
	int tmp=-1;
	vector<int>st;
	try{
		rep(rb,0,r-l+1){
			function<void(int,int,int)>dfs=[&](int i,int take,int nmask){
				if(nmask==mask){
					throw take;
				}
				if(i>=SZ(vs)){
					return;
				}
				dfs(i+1,take,nmask);
				if(take+1<=rb){
					st.pb(vs[i]);
					dfs(i+1,take+1,nmask^vs[i]);
					st.pop_back();
				}
			};
			dfs(0,0,0);
		}
		puts("NO"),exit(0);
	}catch(int x){
		for(auto cur:st){
			int k1=__builtin_ctz(cur);
			int k2=__builtin_ctz(cur^(1<<k1));
			int k3=__builtin_ctz(cur^(1<<k1)^(1<<k2));
			ps(k1+l,k2+l,k3+l);
		}
		assert(count(a+1,a+1+n,0)==n);
	}
}
mt19937 rng(233);
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	//rep(i,1,n)a[i]=rng()&1;
	for(int i=1;i<=n;){
		if(i+14>n){
			brute(i,n);
			break;
		}else{
			i=sol(i);
		}
	}
	puts("YES");
	printf("%d\n",SZ(ans));
	for(auto x:ans)printf("%d %d %d\n",x[0],x[1],x[2]);
	return 0;
}