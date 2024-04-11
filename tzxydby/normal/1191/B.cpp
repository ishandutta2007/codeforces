#include<bits/stdc++.h>
using namespace std;
int s[15][5];
int k[300];
int main()
{
	int a,b,c;
	char x,y,z;
	cin>>a>>x>>b>>y>>c>>z;
	k['m']=1;
	k['p']=2;
	k['s']=3;
	s[a][k[x]]++,s[b][k[y]]++,s[c][k[z]]++;
	int ans=3;
	for(int i=1;i<=9;i++)
		for(int j=1;j<=3;j++)
			ans=min(ans,3-s[i][j]);
	for(int i=1;i<=7;i++)
		for(int j=1;j<=3;j++)
			ans=min(ans,3-(s[i][j]>=1)-(s[i+1][j]>=1)-(s[i+2][j]>=1));
	cout<<ans<<endl;
	return 0;
}