#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		assert(n!=-1);
		auto query=[&](auto&v)->string{
			if(v.empty())return "";
			printf("Q %d ",SZ(v));
			for(auto&x:v)printf("%d %d ",get<0>(x),get<1>(x));
			puts("");
			fflush(stdout);
			string res;
			cin>>res;
			return res;
		};
		vector<int>eq(n+1);
		rep(start,1,2){
			vector<tuple<int,int> >v;
			for(int i=start;i<n;i+=2){
				v.eb(i,i+1);
			}
			string res(query(v));
			for(int i=start,j=0;i<n;i+=2,++j){
				eq[i]=res[j]=='1';
			}
		}
		vector<tuple<int,int> >segs;
		for(int i=1,j;i<=n;i=j){
			j=i+1;
			while(j<=n&&eq[j-1])++j;
			segs.eb(i,j-1);
		}
		vector<int>eq_(SZ(segs)); // [0..SZ(segs)-3]
		for(auto&start:{0,2}){
			vector<tuple<int,int> >v;
			for(int i=start;i<SZ(segs);i+=4){
				if(i+2<SZ(segs)){
					v.eb(get<0>(segs[i]),get<0>(segs[i+2]));
				}
				if(i+3<SZ(segs)){
					v.eb(get<0>(segs[i+1]),get<0>(segs[i+3]));
				}
			}
			string res(query(v));
			for(int i=start,j=0;i<SZ(segs);i+=4,j+=2){
				if(i+2<SZ(segs)){
					eq_[i]=res[j]=='1';
				}
				if(i+3<SZ(segs)){
					eq_[i+1]=res[j+1]=='1';
				}
			}
		}
		vector<int>ans(n+1);
		rep(i,0,SZ(segs)-1){
			int bel;
			if(i<=1){
				bel=i+1;
			}else{
				bel=eq_[i-2]?ans[get<0>(segs[i-2])]:6-ans[get<0>(segs[i-2])]-ans[get<0>(segs[i-1])];
			}
			int l,r;
			tie(l,r)=segs[i];
			rep(j,l,r)ans[j]=bel;
		}
		vector<int>bin[4];
		rep(i,1,n)bin[ans[i]].pb(i);
		printf("A %d %d %d\n",SZ(bin[1]),SZ(bin[2]),SZ(bin[3]));
		rep(i,1,3){
			for(auto&x:bin[i]){
				printf("%d ",x);
			}
			puts("");
		}
		fflush(stdout);
	}
	return 0;
}
/*
1
3
0 0 1
*/