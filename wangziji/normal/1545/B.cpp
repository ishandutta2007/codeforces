#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int jc[100005],jcinv[100005],inv[100005];
inline int C(int x,int y)
{
	return (long long)jc[x]*jcinv[y]%mod*jcinv[x-y]%mod;
}
int main(int argc, char** argv) {
	int T;
	cin >> T;
	jc[0]=jcinv[0]=jc[1]=jcinv[1]=inv[1]=1;
	for(int i=2;i<=100000;i++)
	{
		jc[i]=(long long)jc[i-1]*i%mod;
		inv[i]=(long long)(mod-mod/i)*inv[mod%i]%mod;
		jcinv[i]=(long long)jcinv[i-1]*inv[i]%mod;
	}
	while(T--)
	{
		int n;
		cin >> n;
		string a;
		cin >> a;
		int flag=0;
		int cnt=0,qwq=0,qaq=0;
		a=' '+a;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='1')
			{
				++cnt;
			}
			else qaq+=cnt/2,++qwq,cnt=0;
		}
		cout << C(qaq+qwq+cnt/2,qwq) << "\n";
	}
	return 0;
}