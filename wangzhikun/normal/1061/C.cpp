#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
const int N = 100010,mod = 1e9+7;
int add(int a,int b){
	return a+b>=mod?a+b-mod:a+b;
}
int n,dp[N] = {0},ans = 0,isnp[100020] = {0};
vector<int> pr,nu;
int pri[30],num[30],pn,cu;
void dfs(int cu,int dep){
	if(cu>N)return;
	if(dep == pn){
		nu.push_back(cu);
		return;
	}
	for(int i=0;i<=num[dep];i++){
		dfs(cu,dep+1);
		cu*=pri[dep];
	}
}
int main() {
	read(n);
	dp[0] = 1;
	for(int i=2;i<N;i++){
		if(!isnp[i]){
			pr.push_back(i);
			for(int j = i+i;j<N;j+=i)isnp[j] = 1;
		}
	}
	for(int i=0;i<n;i++){
		read(cu);
		pn = 0;
		for(int i=0;i<pr.size() && pr[i]*pr[i]<=cu;i++){
			if(cu%pr[i] == 0){
				num[pn] = 0;pri[pn] = pr[i];
				while(cu%pr[i] == 0){
					++num[pn];
					cu/=pr[i];
				}
				pn++;
			}
		}
		if(cu!=1){
			num[pn] = 1;pri[pn] = cu;
			pn++;
		}
		nu.clear();
		dfs(1,0);
		sort(nu.begin(),nu.end());
		for(int i=nu.size()-1;i>=0;i--){
			
			dp[nu[i]] = add(dp[nu[i]],dp[nu[i]-1]);
		}
	}
	for(int i=1;i<N;i++){
		ans = add(ans,dp[i]);
	}
	cout<<ans<<'\n';
	return 0;
}