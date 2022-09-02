#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=200005;
int T,n,a[N],id[N],id0;
bool ban[N];
LL S,c[N],ans[N];
set<int>se;
map<int,vector<tuple<int,int> > >cycs;
void exgcd(LL a,LL b,LL&x,LL&y){
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int main(){
	scanf("%d%d",&T,&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,2,n)c[i]=c[i-1]+a[i];
	S=c[n]+a[1];
	LL d=__gcd<LL>(S,T);
	LL S_=S/d,T_=T/d;
	rep(i,1,n){
		if(!get<1>(se.insert(c[i]%T))){
			ban[i]=1;
		}else{
			LL cur=(c[i]%T-c[i]%d)/d;
			// S_*pos=cur(mod T_)
			// pos=?
			LL pos,tmp;
			exgcd(S_,T_,pos,tmp);
			//assert(pos*S_+T_*tmp==1);
			pos=(pos%T_+T_)%T_;
			pos=pos*cur%T_;
			//assert(1LL*S_*pos%T_==cur%T_);
			cycs[c[i]%d].eb(pos,i);
		}
	}
	auto norm1=[&](LL x){
		x=x%T_;
		if(x<=0)x+=T_;
		return x;
	};
	for(auto&_:cycs){
		vector<tuple<int,int> >&cyc=get<1>(_);
		sort(cyc.begin(),cyc.end());
		rep(i,0,SZ(cyc)-1){
			ans[get<1>(cyc[i])]=norm1(get<0>(cyc[(i+1)%SZ(cyc)])-get<0>(cyc[i]));
		}
	}
	rep(i,1,n)printf("%lld ",ans[i]);
	return 0;
}