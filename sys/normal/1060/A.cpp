#include <bits/stdc++.h>
using namespace std;
string str;
int n,ans;
int main()
{
	scanf("%d",&n);
	cin>>str;
	for(int i=0;i<n;i++) if(str[i]=='8') ans++;
	printf("%d",min(ans,(int)floor(n/11.0)));
	return 0;
}