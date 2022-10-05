#include <bits/stdc++.h>
using namespace std;
string str;
int vis[30],cnt,ct;
int main()
{
	cin>>str;
	for(int i=0;i<str.size();i++)
		vis[str[i]-'a'+1]++;
	for(int i=1;i<=26;i++)
	{
		if(vis[i]==1) ct++;
		if(vis[i]>1) cnt++;
	}
	if((ct==0&&cnt==3)||(ct==0&&cnt==4)||(ct==0&&cnt==2)||(ct==1&&cnt==3)||(ct==1&&cnt==2)||(ct==2&&cnt==2)||(ct==2&&cnt==1)||(ct==3&&cnt==1)||(cnt==0&&ct==4)) printf("Yes");
	else printf("No");
	return 0;
}