#include <bits/stdc++.h>
using namespace std;
int cnt1,cnt2,n;
long long ans;
string str;
int main()
{
	cin>>str;
	n=str.size();
	for(int i=0;i<n;i++)
	{
		if(str[i]=='v') cnt2++;
		if(str[i]=='o'&&i&&str[i-1]=='v') cnt2--;
	}
	if(str[n-1]=='v') cnt2--;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='v') cnt1++,cnt2--;
		if(str[i]=='o')
		{
			if(i&&str[i-1]=='v')
				cnt1--,cnt2++;
			ans+=cnt1*(long long)cnt2;
		}
	}
	printf("%lld",ans);
	return 0;
}