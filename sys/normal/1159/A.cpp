#include <bits/stdc++.h>
using namespace std;
int n,cnt;
string str;
int main()
{
	scanf("%d",&n);
	cin>>str;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='-') cnt--;
		if(str[i]=='+') cnt++;
		cnt=max(cnt,0);
	}
	printf("%d",cnt);
	return 0;
}