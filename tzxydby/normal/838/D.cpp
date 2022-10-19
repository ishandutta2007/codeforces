#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}return ans;}
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	printf("%d\n",1ll*(n+1-m)*qp(n+1,mod-2)%mod*qp(2*(n+1),m)%mod);
	return 0;
}