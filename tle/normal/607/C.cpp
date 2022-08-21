//99739771
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int MOD=99739771,pw=233;
char rv[2333333];
typedef long long ll;
int T,n;
ll ps[2333333];
char s1[2333333],s2[2333333];
void sol()
{
	scanf("%d%s%s",&n,s1,s2); --n;
	reverse(s1,s1+n);
	for(int i=0;s1[i];i++) s1[i]=rv[s1[i]];
	bool ok=1;
	ll h1=0,h2=0;
	for(int i=0;i<n;i++)
	{
		h1=h1*pw%MOD+s1[i]; h1%=MOD;
		h2=h2+ps[i]*s2[n-1-i]%MOD; h2%=MOD;
		if(h1==h2) ok=0;
	}
	if(ok) puts("YES"); else puts("NO");
}
int main()
{
	ps[0]=1;
	for(int i=1;i<=1000006;i++) ps[i]=ps[i-1]*pw%MOD;
	rv['N']='S'; rv['S']='N';
	rv['E']='W'; rv['W']='E';
	//scanf("%d",&T); while(T--)
	sol();
}