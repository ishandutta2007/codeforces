#include <bits/stdc++.h>
using namespace std;
string str;
int k,cnt,ans,now,siz;
int main()
{
	scanf("%d%d",&siz,&k);
	cin>>str;
	for(int i=1;i<=26;i++)
	{
		now=cnt=0;
		for(int j=0;j<siz;j++)
		{
			if(str[j]-'a'+1!=i) now=0;
			else now++;
			if(now==k) cnt++,now=0;
		}
		ans=max(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}