#include<bits/stdc++.h>
using namespace std;
char x[3],y[3];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,i,ans=1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%s",y);
		if(i!=1&&x[0]!=y[0]) ans++;
		x[0]=y[0];
	}
	cout<<ans;
	return 0;
}