#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;string s;
	scanf("%i",&n);
	cin >> s;
	int o=0;
	for(i=0;i<s.size();i++) if(s[i]=='8') o++;
	int sol=0;
	while(o && n>=11)
	{
		sol++;
		o--;n-=11;
	}
	printf("%i\n",sol);
	return 0;
}