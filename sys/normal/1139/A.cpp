#include <bits/stdc++.h>
using namespace std;
string str;
int n;
long long ans; 
int main()
{
	scanf("%d",&n);
	cin>>str;
	for(int i=0;i<n;i++)
		if((str[i]-'0')%2==0) ans+=i+1;
	printf("%lld",ans);
	return 0;
}