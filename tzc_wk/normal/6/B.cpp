#include <iostream>
using namespace std;
int n,m,b[256],ans;
char q,a[150][150];
int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	if(a[i][j]==q)
	b[a[i-1][j]]=b[a[i+1][j]]=b[a[i][j-1]]=b[a[i][j+1]]=1;
	for(int i='A';i<='Z';i++) ans+=b[i];
	cout<<ans-b[q];
	return 0;
}