#include<bits/stdc++.h>
using namespace std;
const int N=50005;
vector<string>a;
int c[N],r[N];
int main()
{
	ios::sync_with_stdio(false);
	int q;
	cin>>q;
	while(q--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			c[i]=0;
		for(int i=0;i<m;i++)
			r[i]=0;
		a.clear();
		string s;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			a.push_back(s);
			for(int j=0;j<m;j++)
			{
				if(a[i][j]=='*')
				{
					c[i]++;
					r[j]++;
				}
			}
		}	
		int ans=INT_MAX;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int tot=n+m-1;
				tot-=c[i]+r[j];
				if(a[i][j]=='*')
					tot++;
				ans=min(ans,tot); 
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}