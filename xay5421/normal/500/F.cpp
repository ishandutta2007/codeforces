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
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	int n,p;
	scanf("%d%d",&n,&p);
	vector<tuple<int,int,int> >v(n);
	rep(i,0,n-1){
		int c,h,t;
		scanf("%d%d%d",&c,&h,&t);
		v[i]={t,c,h};
	}
	sort(v.begin(),v.end());
	int Q;
	scanf("%d",&Q);
	vector<tuple<int,int,int> >qs(Q);
	rep(i,0,Q-1){
		int a,b;
		scanf("%d%d",&a,&b);
		qs[i]={a,b,i};
	}
	sort(qs.begin(),qs.end());
	int l=0,r=0; // [)
	vector<array<int,4001> >A,B;
	vector<pair<int,int> >eles;
	auto put=[&](vector<array<int,4001> >&f,int c,int h){
		auto dp=f.empty()?array<int,4001>{0}:f.back();
		per(i,4000,c){
			dp[i]=max(dp[i],dp[i-c]+h);
		}
		f.eb(move(dp));
	};
	auto ps=[&](int c,int h){
		put(B,c,h);
		eles.eb(c,h);
	};
	auto pop=[&](){
		if(!A.empty()){
			A.pop_back();
		}else{
			while(!B.empty()){
				int c_,h_;
				tie(c_,h_)=eles.back();
				B.pop_back();
				eles.pop_back();
				if(!B.empty())put(A,c_,h_);
			}
		}
	};
	vector<int>ans(Q);
	for(auto&x:qs){
		int a,b,id;
		tie(a,b,id)=x;
		while(r<SZ(v)&&get<0>(v[r])<=a){
			ps(get<1>(v[r]),get<2>(v[r])),++r;
		}
		while(l<r&&get<0>(v[l])+p-1<a)
			pop(),++l;
		if(A.empty()){
			if(B.empty()){
				ans[id]=0;
			}else{
				ans[id]=B.back()[b];
			}
		}else{
			if(B.empty()){
				ans[id]=A.back()[b];
			}else{
				int res=0;
				rep(i,0,b){
					res=max(res,A.back()[i]+B.back()[b-i]);
				}
				ans[id]=res;
			}
		}
	}
	rep(i,0,Q-1)printf("%d\n",ans[i]);
	return 0;
}