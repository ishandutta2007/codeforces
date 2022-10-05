#include <bits/stdc++.h>
using namespace std;
string str,ans;
int k,cnt,c1,c2;
int main()
{
	cin>>str;
	scanf("%d",&k);
	int siz=str.size();
	for(int i=0;i<siz;i++)
	{
		if(str[i]=='*'&&cnt) c1++;
		if(str[i]=='?'&&cnt) c2++;
		if(str[i]!='*'&&str[i]!='?') cnt++;
	}
	if(k<cnt-c1-c2)
	{
		printf("Impossible");
		return 0;
	}
	if(!c1&&cnt<k)
	{
		printf("Impossible");
		return 0;
	}
	if(c1)
	{
		if(k<cnt)
		{
			bool tag=true;
			for(int i=0;i<siz;i++)
			{
				if(str[i]!='*'&&str[i]!='?')
				{
					if(i+1<siz)
					{
						if((str[i+1]=='*'||str[i+1]=='?')&&tag) cnt--;
						else ans+=str[i];
					}
					else
						if(str[i]!='*'&&str[i]!='?')
							ans+=str[i];
				}
				if(cnt==k) tag=false;
			}
			cout<<ans;
		}
		else
		{
			bool tag=false;
			for(int i=0;i<siz;i++)
			{
				if(i+1<siz&&!tag&&str[i+1]=='*')
				{
					tag=true;
					for(int j=1;j<=k-(cnt-c2)+1;j++) ans+=str[i];
				}
				else if(str[i]!='*'&&str[i]!='?')
				{
					if(i+1<siz)
					{
						if(str[i+1]=='?') continue;
						else ans+=str[i];
					}
					else
						if(str[i]!='*'&&str[i]!='?')
							ans+=str[i];
				}
			}
			cout<<ans;
		}
	}
	else
	{
		int dif=cnt-k;
		for(int i=0;i<siz;i++)
		{
			if(str[i]!='?')
			{
				if(i+1<siz)
				{
					if(str[i+1]=='?'&&dif)
						dif--;
					else ans+=str[i];
				}
				else ans+=str[i];
			}
		}
		cout<<ans;
	}
	return 0;
}