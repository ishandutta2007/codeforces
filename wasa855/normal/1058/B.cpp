#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n,d,q;
	cin>>n>>d>>q;
	int u,v;
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&u,&v);
		if(u+v<d||u+v>n+n-d||u-v>d||v-u>d)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
		}
	}
	return 0;
}