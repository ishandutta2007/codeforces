#include <bits/stdc++.h>
using namespace std;
string siza[105],sizb[105];
int ans,n,lef,Ma[5],Mb[5],La[5],Lb[5],Sa[5],Sb[5];
bool vis[105];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>siza[i];
	for(int i=1;i<=n;i++)
		cin>>sizb[i];
	for(int i=1;i<=n;i++)
	{
		if(siza[i][siza[i].size()-1]=='M') Ma[siza[i].size()-1]++;
		if(siza[i][siza[i].size()-1]=='S') Sa[siza[i].size()-1]++;
		if(siza[i][siza[i].size()-1]=='L') La[siza[i].size()-1]++;
		if(sizb[i][sizb[i].size()-1]=='M') Mb[sizb[i].size()-1]++;
		if(sizb[i][sizb[i].size()-1]=='S') Sb[sizb[i].size()-1]++;
		if(sizb[i][sizb[i].size()-1]=='L') Lb[sizb[i].size()-1]++;
	}
	for(int i=0;i<=3;i++)
	{
		Ma[i]=(Ma[i]<=Mb[i])?0:Ma[i]-Mb[i];
		Sa[i]=(Sa[i]<=Sb[i])?0:Sa[i]-Sb[i];
		La[i]=(La[i]<=Lb[i])?0:La[i]-Lb[i];
		ans+=(Ma[i]+Sa[i]+La[i]);
	}
	printf("%d",ans);
	return 0;
}