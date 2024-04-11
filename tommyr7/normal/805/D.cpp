#include <bits/stdc++.h>
#define modp 1000000007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
string s;
long long ans,cnt;
int main()
{
	cin>>s;
	ans=0,cnt=0;
	for (int i=s.length()-1;i>=0;i--)
		if (s[i]=='a')
		{
			ans=(ans+cnt)%modp;
			cnt=(2LL*cnt)%modp;
		} else cnt=(cnt+1)%modp;
	cout << ans << endl;
	return 0;
}