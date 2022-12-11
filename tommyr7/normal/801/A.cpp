#include <bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return (long long)x*f;
}
string s;
int ans,now;
int main()
{
	cin>>s;
	ans=0,now=0;
	for (int i=0;i<s.length();i++)
	{
		s[i]='V'+'K'-s[i];
		now=0;
		for (int j=0;j<s.length()-1;j++)
			if (s[j]=='V'&&s[j+1]=='K') ++now;
		if (now>ans) ans=now;
		s[i]='V'+'K'-s[i];
	}
	now=0;
	for (int j=0;j<s.length()-1;j++)
			if (s[j]=='V'&&s[j+1]=='K') ++now;
	if (now>ans) ans=now;
	cout << ans << endl;
	return 0;
}