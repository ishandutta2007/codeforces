#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=1005;
ll a[N][N];
bool type;
int n,Qcnt;
ll V;
ll rnd(){
	ll x=0;
	For(i,1,18)
		x=x*10+rand()%10;
	return x;
}
void init(){
	type=1;
	For(i,1,n){
		int top=0;
		for (;top!=V;){
			for (;top!=V;a[i][++top]=rnd());
			sort(a[i]+1,a[i]+V+1);
			top=unique(a[i]+1,a[i]+V+1)-a[i]-1;
		}
	}
}
ll query(int x,ll y){
	++Qcnt;
	if (type==0){
		printf("? %d %lld\n",x,y);
		fflush(stdout);
		scanf("%lld",&y);
		return y;
	}
	else{
		int pos=upper_bound(a[x]+1,a[x]+V*n+1,y)-a[x]-1;
		return pos;
	}
}
int id[N],idd[N];
ll val[N],ansR[N],ansL[N];
bool cmp(int x,int y){
	return val[x]<val[y];
}
map<pll,ll> mp;
ll find(int x,ll L,ll R,ll val){
	if (mp.find(pll(x,val))!=mp.end())
		return mp[pll(x,val)];
	ll ans=0;
	for (;L<=R;){
		ll mid=(L+R)/2;
		ll v=query(x,mid);
		if (v==val) ans=mid;
		if (v>=val) R=mid-1;
		else L=mid+1;
	}
	return mp[pll(x,val)]=ans;
}
void divide(ll L,ll R,ll l,ll r){
	if (l>r) return;
	if (L==R){
		For(i,l,r) ansR[id[i]]=L;
		return;
	}
	if (l==r){
		ansR[id[l]]=find(id[l],L,R,l*V);
		assert(ansR[id[l]]!=0);
		return;
	}
	int mid=(l+r)/2;
	int pl=l,pr=r;
	ll LL=L,RR=R;
	for (;;){
		int speP=id[pl+rand()%(pr-pl+1)];
		ll pos=find(speP,LL,RR,mid*V);
		int plll=pl,prrr=pr;
		For(i,pl,pr){
			ll val=query(id[i],pos);
			if (val>mid*V||(val==mid*V&&id[i]<=speP)) idd[plll++]=id[i];
			else idd[prrr--]=id[i];
		}
		For(i,pl,pr) id[i]=idd[i];
		if (prrr<=mid)
			pl=prrr+1,LL=pos;
		else pr=plll-1,RR=pos;
		if (pr<=mid||pl>mid) break;
	}
	divide(L,RR,l,mid);
	divide(LL,R,mid+1,r);
}
void output(){
	For(i,1,n)
		ansL[id[i]]=ansR[id[i-1]];
	printf("!\n");
	For(i,1,n)
		printf("%lld %lld\n",ansL[i],ansR[i]);
	fflush(stdout);
}
int main(){
	scanf("%d%lld",&n,&V);
	srand(time(NULL));
	V/=n;
	For(i,1,n) id[i]=i;
	divide(0,1000000000000000000ll,1,n);
	output();
}