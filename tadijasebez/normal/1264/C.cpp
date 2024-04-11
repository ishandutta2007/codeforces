#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int mod=998244353;
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
void ckadd(int &x,int y){x=add(x,y);}
int sub(int x,int y){x-=y;return x<0?x+mod:x;}
void cksub(int &x,int y){x=sub(x,y);}
int mul(int x,int y){return (ll)x*y%mod;}
void ckmul(int &x,int y){x=mul(x,y);}
int pow(int x,int k){int ans=1;for(;k;k>>=1,ckmul(x,x))if(k&1)ckmul(ans,x);return ans;}
int inv(int x){return pow(x,mod-2);}
set<int> chk;
const int N=200050;
struct ST{
	pii node[N<<1];
	pii cmb(pii a,pii b){return (pii){mul(a.first,b.first),add(mul(a.second,b.first),b.second)};}
	void Set(int i,int q){for(i+=N,node[i]={q,q};i>>=1;)node[i]=cmb(node[i<<1],node[i<<1|1]);}
	int Get(int l,int r){
		pii ans_l={0,0},ans_r={0,0};
		bool has_l=0,has_r=0;
		for(l+=N,r+=N;l<=r;l>>=1,r>>=1){
			if(l%2==1) ans_l=has_l?cmb(ans_l,node[l]):node[l],l++,has_l=1;
			if(r%2==0) ans_r=has_r?cmb(node[r],ans_r):node[r],r--,has_r=1;
		}
		if(!has_l)return ans_r.second;
		if(!has_r)return ans_l.second;
		return cmb(ans_l,ans_r).second;
	}
}T;
int p[N],st[N];
int main(){
	int n,q;
	scanf("%i %i",&n,&q);
	chk.insert(1);
	chk.insert(n+1);
	for(int i=1;i<=n;i++)scanf("%i",&p[i]),p[i]=mul(100,inv(p[i])),T.Set(i,p[i]);
	int ans=T.Get(1,n);
	while(q--){
		int i;scanf("%i",&i);
		if(st[i]){
			auto it=chk.find(i);
			cksub(ans,T.Get(i,*next(it)-1));
			cksub(ans,T.Get(*prev(it),i-1));
			chk.erase(i);
			it=chk.upper_bound(i);
			ckadd(ans,T.Get(*prev(it),*it-1));
		}
		else{
			auto it=chk.upper_bound(i);
			cksub(ans,T.Get(*prev(it),*it-1));
			chk.insert(i);
			it=chk.find(i);
			ckadd(ans,T.Get(i,*next(it)-1));
			ckadd(ans,T.Get(*prev(it),i-1));
		}
		st[i]^=1;
		printf("%i\n",ans);
	}
	return 0;
}