#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=105;
const int LOG=61;
const int M=2*N*LOG*4;
const ll lim=((ll)1<<60)-1;
vector<int> nds[2][LOG];
int ls[M],rs[M],tsz,root[2],mark[M];
ll L[M],R[M];
void Add(int t,int &c,ll ss,ll se,ll qs,ll qe,int dep){
	if(qs>qe||qs>se||ss>qe)return;
	if(!c)c=++tsz,nds[t][dep].pb(c),L[c]=ss,R[c]=se;
	if(qs<=ss&&qe>=se){mark[c]=1;return;}
	ll mid=ss+se>>1;
	Add(t,ls[c],ss,mid,qs,qe,dep+1);
	Add(t,rs[c],mid+1,se,qs,qe,dep+1);
}
void rd(int t){
	int n;scanf("%i",&n);
	while(n--){
		ll l,r;scanf("%lld %lld",&l,&r);
		Add(t,root[t],0,lim,l,r,0);
	}
}
#define pii pair<ll,ll>
const int H=16*N*N*LOG;
pii seg[H];
int xb;
const int mod=998244353;
ll gt(ll x){x%=mod;return x*(x+1)%mod*((mod+1)/2)%mod;}
ll gt(ll r,ll l){return gt(r)+mod-gt(l);}
int main(){
	rd(0);rd(1);
	for(int i=0;i<LOG;i++){
		for(int a:nds[0][i])for(int b:nds[1][i])
			if(mark[a]||mark[b])
				seg[++xb]={L[a]^L[b],L[a]^R[b]};
	}
	sort(seg+1,seg+1+xb);
	ll ans=0,r=-1;
	for(int i=1;i<=xb;i++){
		if(seg[i].second>r)ans+=gt(seg[i].second,max(r,seg[i].first-1)),ans%=mod;
		r=max(r,seg[i].second);
	}
	printf("%lld\n",ans);
	return 0;
}