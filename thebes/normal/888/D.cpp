#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll f(ll n, ll k){return(n<=1||!k)?1LL:n*f(n-1,k-1);}
ll N, K, ans, i, p[5]={1,0,1,2,9};

int main(){
	scanf("%I64d%I64d",&N,&K);
	for(i=0;i<=K;i++)
		ans += f(N,i)/f(i,i)*p[i];
	printf("%I64d\n",ans);
	return 0;
}