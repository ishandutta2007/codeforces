#include<bits/stdc++.h>
using namespace std;
const int max_n=1e6+5;
char s[max_n];
int main()
{
	int n;
	scanf("%d%s",&n,s+1);
	int pos=-1;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='1')
		{
			pos=i;
			break;
		}
	}
	if(pos==-1)
	{
		puts("0");
		return 0;
	}
	int pos2=pos;
	while(pos2<=n&&s[pos2]!='0')
		++pos2;
	if(pos2>n)
	{
		for(int i=pos;i<=n;++i)
			putchar('1');
		putchar('\n');
		return 0;
	}
	assert(pos2-pos<=100);
	string s1;
	for(int i=pos;i<=n;++i)
		s1+=s[i];
	string ans=s1;
	int len=n-pos2+1;
	for(int i=pos;i<pos2;++i)
	{
		string t=s1;
		for(int j=1;j<=len;++j)
		{
			int x=i+j-1;
			if(s[x]=='1')
				t[pos2-pos+j-1]='1';
		}
		ans=max(ans,t);
	}
	cout<<ans<<"\n";
	return 0;
}