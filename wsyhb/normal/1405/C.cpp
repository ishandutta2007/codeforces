#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
char s[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k; 
		scanf("%d%d%s",&n,&k,s+1);
		bool flag=true;
		for(int i=1;i+k<=n;++i)
		{
			if(s[i]!='?'&&s[i+k]!='?'&&s[i]!=s[i+k])
			{
				flag=false;
				break;
			}
			if(s[i]!='?') s[i+k]=s[i];
			else s[i]=s[i+k];
		}
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='0') ++cnt0;
			if(s[i]=='1') ++cnt1;
			if(i>k)
			{
				if(s[i-k]=='0') --cnt0;
				if(s[i-k]=='1') --cnt1;
			}
			if(cnt0>k/2||cnt1>k/2)
			{
				flag=false;
				break;
			}
		}
		printf(flag?"YES\n":"NO\n");
	}
	return 0;
}