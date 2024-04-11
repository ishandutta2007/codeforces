#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
int mul(int x,int y){return (ll)x*y%mod;}
int pow(int x,int k){int ans=1;for(;k;k>>=1,x=mul(x,x))if(k&1)ans=mul(ans,x);return ans;}
int inv(int x){return pow(x,mod-2);}
int dv(int x,int y){return mul(x,inv(y));}
int main(){
	int n;
	scanf("%i",&n);
	int ans=0;
	for(int i=1,p;i<=n;i++){
		scanf("%i",&p);
		p=dv(p,100);
		ans=dv(add(ans,1),p);
	}
	printf("%i\n",ans);
	return 0;
}