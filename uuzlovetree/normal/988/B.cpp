#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n;
string s[maxn];
bool cmp(string a,string b)
{
	return a.length()<b.length();
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)cin>>s[i];
	sort(s+1,s+n+1,cmp);
	for(int i=2;i<=n;++i)
	{
		int len1=s[i-1].length(),len2=s[i].length();
		bool yes=0;
		for(int l=0;l+len1-1<=len2;++l)
		{
			bool ok=1;
			for(int j=l;j<=l+len1-1;++j)
			{
				if(s[i][j]!=s[i-1][j-l])ok=0;
			}
			if(ok==1)yes=1;
		}
		if(!yes)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i=1;i<=n;++i)cout<<s[i]<<endl;
	return 0;
}