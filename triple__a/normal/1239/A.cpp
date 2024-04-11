#include<bits/stdc++.h>
using namespace std;

const int maxn=1000007;
const int mod=1e9+7;
int ans[maxn];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	ans[1]=1,ans[2]=2;
	for (int i=3;i<=max(n,m);++i){
		ans[i]=(ans[i-1]+ans[i-2])%mod;
	}
	int u=(ans[n]+ans[m]-1)%mod;
	if (u<0) u+=mod;
	printf("%d\n",2*u%mod);
}