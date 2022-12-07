#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=400005;
int n,top;
ll L[N],R[N],T[N];
pll q[N*2];
struct WZP{
	ll t[N*2];
	int nn,id[N*4];
	int Mn(int x,int y){
		return t[x]<t[y]?x:y;
	}
	void build(int n){
		for (nn=1;nn<=n+1;nn<<=1);
		For(i,0,nn-1) t[i]=1ll<<61,id[i+nn]=i;
		Rep(i,nn-1,1) id[i]=Mn(id[i*2],id[i*2+1]);
	}
	void change(int x,ll v){
		t[x]=v; x+=nn;
		for (x>>=1;x;x>>=1)
			id[x]=Mn(id[x*2],id[x*2+1]);
	}
}TR1,TR2;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld%lld%lld",&L[i],&R[i],&T[i]);
	For(i,1,n){
		q[++top]=pll(L[i],i);
		q[++top]=pll(R[i]-T[i]+1,-i);
	}
	sort(q+1,q+top+1);
	TR1.build(n);
	TR2.build(n);
	For(i,1,n) TR1.change(i,L[i]+T[i]);
	int pos=1;
	ll clk=0,tms=0;
	for (;pos<=top;){
		int p1=TR1.id[1],p2=TR2.id[1];
		ll v1=(clk<L[p1]&&p1>=1&&p1<=n?L[p1]+T[p1]:1ll<<61);
		ll v2=(clk<=R[p2]-T[p2]&&p2>=1&&p2<=n?clk+T[p2]:1ll<<61);
		//printf("%lld %lld %lld %d %d\n",clk,v1,v2,p1,p2);
		if (v1<=v2) clk=v1,++tms;
		else{
			ll ed=min(v1,R[p2]);
			ll wzp=(ed-clk)/T[p2];
			clk+=wzp*T[p2]; tms+=wzp;
		}
		for (;pos<=top&&q[pos].fi<=clk;++pos)
			if (q[pos].se<0)
				TR2.change(-q[pos].se,1ll<<61);
			else{
				TR1.change(q[pos].se,1ll<<61);
				TR2.change(q[pos].se,T[q[pos].se]);
			}
	}
	printf("%lld\n",tms);
}
/*
2
5 7 1
1 9 2

3 
1 10 4
6 12 3
9 13 2

3
1 13 4
6 11 2
9 13 3
*/