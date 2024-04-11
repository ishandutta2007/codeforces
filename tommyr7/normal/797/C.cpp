#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
string s;
char ch[Maxn];
bool vis[Maxn];
int mn[Maxn],m,top;
int main()
{
	cin>>s;
	memset(vis,false,sizeof(vis));
	memset(mn,0,sizeof(mn));
	mn[s.length()-1]=s.length()-1;
	for (int i=s.length()-2;i>=0;i--) if (s[i]<=s[mn[i+1]]) mn[i]=i; else mn[i]=mn[i+1];
	m=0,top=0;
	int now=0;
	while (now<s.length())
	{
		if (now==0||m==0||s[mn[now]]<ch[m])
		{
			for (int j=now;j<mn[now];j++) ch[++m]=s[j];
			cout << s[mn[now]];
			now=mn[now]+1;
		} else
		{
			cout << ch[m];
			--m;
		}
	}
	if (m>0)
	{
		for (int i=m;i;i--) cout << ch[i];
	}
	cout << endl;
	return 0;
}