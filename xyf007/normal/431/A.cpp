#include<bits/stdc++.h>
using namespace std;
string s;
int a[5];
int main()
{
	for(int i=1;i<=4;i++)
	  scanf("%d",&a[i]);
	getchar();
	cin>>s;
	long long ans=0;
	for(int i=0;i<s.size();i++)
	  ans+=a[s[i]-'0'];
	printf("%lld",ans);
	return 0;
}