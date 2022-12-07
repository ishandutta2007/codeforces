#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int sum;
vector<ll> vec[11];
const int moo=100017;
struct Hashset{
	ll key[40005];
	ll val[40005];
	int nxt[40005];
	int head[moo],nd;
	ll& operator [](const ll &x){
		for (int i=head[x%moo];i;i=nxt[i])
			if (key[i]==x) return val[i];
		key[++nd]=x; nxt[nd]=head[x%moo]; head[x%moo]=nd;
		return val[nd];
	}
	ll findv(const ll &x)const{
		for (int i=head[x%moo];i;i=nxt[i])
			if (key[i]==x) return val[i];
		return 0;
	}
}vf[20][11];
void dfs(int x,int y,int s,ll st,bitset<100> S){
	if (!S[s/2]){
		int p=s/2;
		for (;!S[p];--p);
		vec[s-p*2].PB(st);
	}
	if (x>18) return;
	int pl=s/2,pr=s/2;
	for (;pl>=0&&S[pl];--pl);
	for (;pr<100&&S[pr];++pr);
	if (pr-pl-1>=9) return;
	for (int i=y;i<=9;i++)
		dfs(x+1,i,s+i,st+(1ll<<(5*i)),S|(S<<i));	
}
void init(){
	bitset<100> S; S[0]=1;
	dfs(1,1,0,0,S);
	For(i,2,9){
		sort(vec[i].begin(),vec[i].end());
		for (auto j:vec[i]) ++vf[0][i][j];
	}
	For(i,1,18) For(j,2,9)
		For(p,1,vf[i-1][j].nd){
			pll k(vf[i-1][j].key[p],vf[i-1][j].val[p]);
			vf[i][j][k.fi]+=k.se;
			For(l,1,9) if ((k.fi>>(5*l))&31)
				vf[i][j][k.fi-(1ll<<(5*l))]+=k.se;
		}
}
ll FFF(int i,ll j,int k){
	return vf[i][k].findv(j);
}
ll FF(ll l,int k){
	if (l%2==1) return (l+1)/2;
	int tmp=0;
	for (ll x=l;x;tmp+=x%10,x/=10);
	return (l+1)/2+(tmp%2==k);
}
ll F(ll l,int k){
	static int a[20],top; l++;
	for (top=0;l;a[++top]=l%10,l/=10);
	ll st=0,ans=0;
	Rep(i,top,1){
		For(j,0,a[i]-1) ans+=FFF(i-1,st+(j?1ll<<(5*j):0),k);
		if (a[i]) st+=1ll<<(5*a[i]);
	}
	return ans;
}
int main(){
	init();
	int Q;
	scanf("%d",&Q);
	while (Q--){
		ll l,r,k,ans=0;
		scanf("%lld%lld%lld",&l,&r,&k); 
		if (k==0){
			ans=FF(r,0)-FF(l-1,0);
			for (k+=2;k<=9;k+=2)
				ans-=F(r,k)-F(l-1,k);
		}
		else{
			ans=r-l+1;
			for (k++;k<=9;k++)
				ans-=F(r,k)-F(l-1,k);
		}
		printf("%lld\n",ans);
	} 
}