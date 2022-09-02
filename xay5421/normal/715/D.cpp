// author: xay5421
// created: Fri Nov 12 08:54:34 2021
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
LL T,pw[30];
int n=2;
vector<tuple<int,int,int,int> >ans;
void ps(int a,int b,int c,int d){
	ans.eb(a,b,c,d);
	ans.eb(b,a,d,c);
}
void ps_(int a,int b,int c,int d){
	ans.eb(a,b,c,d);
}
void sol(int x){
	assert(0<=x&&x<6);
	if(n==2){
		rep(i,0,2){
			if(x>=3&&i==1){
				ps_(n,n+i,n-1,n+i);
				x-=3;
			}else if(i==2){
				if(x==0){
					ps(n,n+i,n-1,n+i);
				}else if(x==1){
					ps_(n,n+i,n-1,n+i);
				}
			}else{
				ps(n,n+i,n-1,n+i);
			}
		}
		rep(i,0,1){
			ps(n+2,n+i,n+3,n+i);
		}
		/*rep(i,0,1){
			ps(n-1+i,n+3,n-1+i,n+4);
		}*/
	}else{
		rep(i,1,2){
			if(x>=3&&i==1){
				ps_(n,n+i,n-1,n+i);
				x-=3;
			}else if(i==2){
				if(x==0){
					ps(n,n+i,n-1,n+i);
				}else if(x==1){
					ps_(n,n+i,n-1,n+i);
				}
			}else{
				ps(n,n+i,n-1,n+i);
			}
		}
		rep(i,0,1){
			ps(n+2,n+i,n+3,n+i);
		}
		rep(i,0,1){
			ps(n+i+2,n-1,n+i+2,n-2);
		}
		/*rep(i,0,1){
			ps(n-1+i,n+3,n-1+i,n+4);
		}*/
	}
	n+=2;
}
int main(){
	pw[0]=1;
	rep(i,1,24)pw[i]=pw[i-1]*6;
	scanf("%lld",&T);
	vector<int>num;
	{
		LL x=T;
		while(x>0){
			num.pb(x%6);
			x/=6;
		}
	}
	per(i,SZ(num)-1,0){
		sol(num[i]);
	}
	{
		vector<tuple<int,int,int,int> >ans_;
		auto chk=[&](int x,int y){
			return 1<=x&&x<=n&&1<=y&&y<=n;
		};
		for(const auto&x:ans){
			if(chk(get<0>(x),get<1>(x))&&chk(get<2>(x),get<3>(x))){
				ans_.pb(x);
			}
		}
		ans=move(ans_);
	}
	/*vector<vector<LL> >dp(n+1,vector<LL>(n+1,0));
	dp[1][1]=1;
	auto chk=[&](int a,int b,int c,int d){
		return find(ans.begin(),ans.end(),make_tuple(a,b,c,d))==ans.end()&&find(ans.begin(),ans.end(),make_tuple(c,d,a,b))==ans.end();
	};
	rep(i,1,n){
		rep(j,1,n){
			if(i>1&&chk(i-1,j,i,j))dp[i][j]+=dp[i-1][j];
			if(j>1&&chk(i,j-1,i,j))dp[i][j]+=dp[i][j-1];
		}
	}
	D("ff=%lld\n",dp[n][n]);*/
	printf("%d %d\n",n,n);
	printf("%d\n",SZ(ans));
	for(const auto&x:ans){
		if(get<0>(x)>get<2>(x)||get<1>(x)>get<3>(x)){
			printf("%d %d %d %d\n",get<2>(x),get<3>(x),get<0>(x),get<1>(x));
		}else{
			printf("%d %d %d %d\n",get<0>(x),get<1>(x),get<2>(x),get<3>(x));
		}
	}
	return 0;
}