#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s,t;
	int n,i,j;
	scanf("%i",&n);
	cin >> s;j=n-1;
	for(i=0;i+1<n;i++)
	{
		if(s[i]>s[i+1]){ j=i;break;}
	}
	for(i=0;i<n;i++) if(i!=j) t+=s[i];
	cout << t;
	return 0;
}