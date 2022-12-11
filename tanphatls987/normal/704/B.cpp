#include <bits/stdc++.h>

using namespace std;

#define X first 
#define Y second 
#define FOR(i,L,R) for(auto i=(L);i<=(R);i++)
#define REP(i,L,R) for(auto i=(L);i<(R);i++)

typedef pair<int,int> ii;
typedef long long ll;

const int MOD=1e9+7;
const int N=5e3+10;
const ll linf=1e16;

int n,st,en;
ll f[N][N];
int a[N],llar[N],lsma[N],jlar[N],jsma[N];
void prepare(){
	scanf("%d%d%d",&n,&st,&en);
	FOR(i,1,n) scanf("%d",a+i);
	FOR(i,1,n) scanf("%d",llar+i);
	FOR(i,1,n) scanf("%d",lsma+i);
	FOR(i,1,n) scanf("%d",jsma+i);
	FOR(i,1,n) scanf("%d",jlar+i);
}
bool possible(int pos,int gr){
	if (gr<=0) return 0;
	if (pos==1&&gr!=1) return 0;
	///still some left
	if (pos<n&&pos>=max(st,en)&&gr==1) return 0;
	return 1;
}
ll DP(int pos,int gr){
	if (!possible(pos,gr)) return linf;
	if (pos==1){
		if (pos==st) return jlar[1];
		if (pos==en) return lsma[1];
		return jlar[1]+lsma[1]; 
	}
	ll &val=f[pos][gr];
	if (val!=-1) return val;
	val=linf;
	ll head=2*gr-(pos>=st)-(pos>=en);
	if (pos==st){
		///to head of a group (go small) 
		val=min(val,DP(pos-1,gr)+1LL*(head+1)*(a[pos]-a[pos-1])+jsma[pos]);
		///alone (go larger)
		val=min(val,DP(pos-1,gr-1)+1LL*(head-1)*(a[pos]-a[pos-1])+jlar[pos]);
		return val;
	}
	if (pos==en){
		///to end of a group (in lar)
		val=min(val,DP(pos-1,gr)+1LL*(head+1)*(a[pos]-a[pos-1])+llar[pos]);
		///alone (in small)
		val=min(val,DP(pos-1,gr-1)+1LL*(head-1)*(a[pos]-a[pos-1])+lsma[pos]);
		return val;
	}
	///to 1 group
	val=min(val,DP(pos-1,gr+1)+1LL*(head+2)*(a[pos]-a[pos-1])+jsma[pos]+llar[pos]);
	///to head of a group
	bool canhead=!(pos>st&&gr==1);
	if (canhead) val=min(val,DP(pos-1,gr)+1LL*head*(a[pos]-a[pos-1])+jsma[pos]+lsma[pos]);
	///to end of a group
	bool canend=!(pos>en&&gr==1);
	if (canend) val=min(val,DP(pos-1,gr)+1LL*head*(a[pos]-a[pos-1])+jlar[pos]+llar[pos]);
	///alone
	val=min(val,DP(pos-1,gr-1)+1LL*(head-2)*(a[pos]-a[pos-1])+jlar[pos]+lsma[pos]);
	// cout<<pos<<" "<<gr<<" "<<val<<'\n';
	return val;
}
int main(){
	prepare();
	memset(f,-1,sizeof(f));
	// cout<<DP(1,1)<<'\n';
	cout<<DP(n,1);
}