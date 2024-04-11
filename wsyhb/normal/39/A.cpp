#include<bits/stdc++.h>
using namespace std;
const int max_len=8999+5;
char s[max_len];
const int max_sz=1e3+5;
int val[max_sz],sz;
int main()
{
	int a;
	scanf("%d%s",&a,s+1);
	int len=strlen(s+1),Last=0,ans=0;
	for(int i=1;i<=len;++i)
	{
		if(i-Last>=3&&((s[i-2]=='a'&&s[i-1]=='+'&&s[i]=='+')||(s[i-2]=='+'&&s[i-1]=='+'&&s[i]=='a')))
		{
			bool flag_minus=false;
			if(Last)
				flag_minus=s[++Last]=='-';
			int v;
			if(i-Last>3)
			{
				v=0;
				for(int j=Last+1;j<=i-4;++j)
				{
					assert(s[j]>='0'&&s[j]<='9');
					v=v*10+(s[j]^'0');
				}
				assert(s[i-3]=='*');
			}
			else
				v=1;
			if(flag_minus)
				v=-v;
			if(s[i]=='a')
				ans+=v;
			val[++sz]=v;
			Last=i;
		}
	}
	sort(val+1,val+sz+1);
	for(int i=1;i<=sz;++i)
		ans+=(a++)*val[i];
	printf("%d\n",ans);
	return 0;
}