//  Created by WangZhikun on 2018/10/29.

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
}
ll obuc[300030] = {0},buc[300030] = {0},C[300030][8] = {0},dp[300030],mod = 614889782588491411;
int n,cu;
inline void add(ll &a,ll b){
	a+=b;
	if(a>=mod)a-=mod;
}
inline void sub(ll &a,ll b){
	a-=b;
	if(a<0)a+=mod;
}
int main() {
	read(n);
	int mx = 0;
	for(int i=0;i<n;i++){
		read(cu);
		obuc[cu] = 1;
		mx = max(cu,mx);
	}
	
	C[0][0] = 1;
	for(int i=1;i<=mx;i++){
		C[i][0] = 1;
		for(int j = i;j<=mx;j+=i)buc[i]+=obuc[j];
		//cout<<i<<' '<<buc[i]<<endl;
	}
	
	for(int ans = 1;ans<8;ans++){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=mx;i++){
			C[i][ans] = C[i-1][ans-1]+C[i-1][ans];
			if(C[i][ans]>=mod)C[i][ans] -= mod;
		}
		for(int i=mx;i>=1;i--){
			dp[i] = C[buc[i]][ans];
			for(int j = i+i;j<=mx;j+=i)sub(dp[i],dp[j]);
		}
		if(dp[1]!=0){
			//cout<<dp[1]<<endl;
			cout<<ans<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}