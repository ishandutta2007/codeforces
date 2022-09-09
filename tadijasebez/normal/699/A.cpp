#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%i",&n);
	string s;
	vector<int> x(n);
	cin>>s;
	for(int &i:x) scanf("%i",&i);
	int ans=-2;
	for(int i=1;i<n;i++) if(s[i]=='L' && s[i-1]=='R' && (ans==-2 || ans>x[i]-x[i-1])) ans=x[i]-x[i-1];
	printf("%i\n",ans/2);
	return 0;
}