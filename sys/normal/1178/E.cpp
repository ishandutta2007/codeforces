#include <bits/stdc++.h>
using namespace std;
int n,cnt[4],pnt;
string str,ans; 
int main()
{
	cin>>str;
	n=str.size();
	for(pnt=0;n-2*pnt-1>=3;pnt+=2)
	{
		cnt[0]=cnt[1]=cnt[2]=0;
		cnt[str[pnt]-'a']++,cnt[str[pnt+1]-'a']++;
		cnt[str[n-pnt-1]-'a']++,cnt[str[n-pnt-2]-'a']++;
		for(int j=0;j<=2;j++)
			if(cnt[j]>=2)
			{
				ans+=j+'a';
				break;
			}
	}
	if(n-2*pnt) ans+=str[pnt];
	int siz=ans.size();
	for(int i=siz-1-(bool)(n-2*pnt);i>=0;i--)
		ans+=ans[i];
	cout<<ans;
	return 0;
}