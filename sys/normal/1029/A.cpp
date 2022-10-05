#include <bits/stdc++.h>
using namespace std;
string str;
int ans,n,m; 
int main()
{
	scanf("%d%d",&n,&m);
	cin>>str;
	for(int i=n-1;i>=1;i--)
	{ 
		int pnt=0;
		while(i+pnt<n&&str[i+pnt]==str[pnt]) pnt++;
		if(i+pnt==n) ans=n-i;
	}
	cout<<str;
	for(int i=2;i<=m;i++)
		for(int j=ans;j<n;j++)
			printf("%c",str[j]);
	return 0;
}