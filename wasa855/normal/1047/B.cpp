#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int u,v;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&u,&v);
		if(u+v>maxn)
		{
			maxn=u+v;
		}
	}
	cout<<maxn<<endl;
	return 0;
}