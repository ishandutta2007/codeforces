#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int n,i,l=0,r=0;
	scanf("%i",&n);cin>>s;
	while(l<n && s[l]==s[0]) l++;
	while(r<n && s[n-r-1]==s[n-1]) r++;
	if(s[0]!=s[n-1]) printf("%i\n",l+r+1);
	else printf("%i\n",(long long)(l+1)*(r+1)%998244353);
	return 0;
}