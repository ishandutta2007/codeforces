#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
uint f[2010][2010],mu[2010],ans;
int a,b,c;
uint ff(int x,int y) {
	if (f[x][y]) return f[x][y];
	uint &res=f[x][y];
	for (int i=1;i<=y;i++) if (__gcd(i,x)==1) res+=y/i;
	return res;
}
int main() {
	scanf("%d%d%d",&a,&b,&c);
	mu[1]=1;
	for (int i=1;i<=2000;i++) for (int j=i+i;j<=2000;j+=i) mu[j]-=mu[i];
	for (int i=1;i<=a;i++) for (int x=1;x<=2000;x++) if (__gcd(i,x)==1)
		ans+=mu[x]*(a/i)*ff(i,b/x)*ff(i,c/x);
	printf("%u\n",ans%(1<<30));
}