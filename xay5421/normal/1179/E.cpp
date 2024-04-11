#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PB push_back
#define EB emplace_back
using namespace std;
typedef long long LL;
int n;
LL L;
pair<LL,LL>ans[1005];
mt19937_64 rng(233);
LL F(int i,LL x){
	printf("? %d %lld\n",i,x);
	fflush(stdout);
	LL y;
	scanf("%lld",&y);
	return y;
}
void sol(vector<pair<int,LL> >cur,LL l,LL r){
	if(SZ(cur)<=1){
		for(auto x:cur){
			ans[x.X]={l,r};
		}
		return;
	}
	vector<pair<int,LL> >can(cur);
	auto get=[&](int i,LL x){
		return F(can[i].X,x)-can[i].Y;
	};
	int bs=0;
	vector<pair<int,LL> >left;
	vector<pair<int,LL> >right;
	int ned=SZ(cur)/2;
	while(1){
		int id=rng()%SZ(can);
		LL lb=l,rb=r,res=-1;
		while(lb<=rb){
			LL mid=(lb+rb)>>1;
			if(get(id,mid)>=ned*(L/n)){
				res=mid;
				rb=mid-1;
			}else{
				lb=mid+1;
			}
		}
		int greater=bs,equal=0;
		vector<LL>w(SZ(can));
		rep(i,0,SZ(can)-1){
			w[i]=get(i,res);
			if(w[i]>ned*(L/n)){
				++greater;
			}else if(w[i]==ned*(L/n)){
				++equal;
			}
		}
		if(greater+1<=ned&&ned<=greater+equal){
			vector<bool>bo(SZ(can));
			rep(i,0,SZ(can)-1){
				if(w[i]>ned*(L/n)){
					left.PB(can[i]);
					bo[i]=1;
				}
			}
			rep(i,0,SZ(can)-1)if(!bo[i]){
				if(w[i]>=ned*(L/n)&&SZ(left)<ned){
					left.PB(can[i]);
				}else{
					right.PB(can[i]);
				}
			}
			for(auto&x:right){
				x.Y=F(x.X,res);
			}
			sol(left,l,res);
			sol(right,res,r);
			return;
		}
		if(greater+1>ned){
			vector<pair<int,LL> >ncan;
			rep(i,0,SZ(can)-1){
				if(w[i]<ned*(L/n)){
					right.PB(can[i]);
				}else ncan.PB(can[i]);
			}
			can=ncan;
		}
		if(ned>greater+equal){
			vector<pair<int,LL> >ncan;
			rep(i,0,SZ(can)-1){
				if(w[i]>=ned*(L/n)){
					left.PB(can[i]);
				}else ncan.PB(can[i]);
			}
			can=ncan;
			bs=greater+equal;
		}
	}
}
int main(){
	scanf("%d%lld",&n,&L);
	vector<pair<int,LL> >tp(n,{0,0});
	rep(i,0,n-1)tp[i].X=i+1;
	sol(tp,0,1e18);
	printf("!\n");
	rep(i,1,n)printf("%lld %lld\n",ans[i].X,ans[i].Y);
	return 0;
}