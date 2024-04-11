#include <bits/stdc++.h>
using namespace std;
string str;
int n,ans,cnt[28]; 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		cnt[str[0]-'a'+1]++;
	}
	for(int i=1;i<=26;i++)
	{
		ans+=cnt[i]/2*(cnt[i]/2-1)/2;
		ans+=(cnt[i]-cnt[i]/2)*((cnt[i]-cnt[i]/2)-1)/2;
	}
	printf("%d",ans);
	return 0;
}