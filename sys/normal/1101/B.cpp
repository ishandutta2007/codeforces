#include <bits/stdc++.h>
using namespace std;
string str;
int l,r,ans;
bool tag1;
int main()
{
	cin>>str;
	int siz=str.size();
	for(int i=0;i<siz;i++)
	{
		if(str[i]=='['&&!tag1) tag1=true,ans++;
		else if(tag1&&str[i]==':')
		{
			ans++,l=i;
			break;
		}
	}
	tag1=false;
	for(int i=siz-1;i>=0;i--)
	{
		if(str[i]==']'&&!tag1) tag1=true,ans++;
		else if(tag1&&str[i]==':')
		{
			ans++,r=i;
			break;
		}
	}
	if(l>=r||ans!=4)
	{
		printf("-1");
		return 0;
	}
	else 
		for(int i=l+1;i<=r-1;i++)
			if(str[i]=='|') ans++;
	printf("%d",ans);
	return 0;
}