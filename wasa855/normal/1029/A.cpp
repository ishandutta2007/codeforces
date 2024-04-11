#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	string t;
	string ans=s;
	for(int i=n;i>0;i--)
	{
		t.clear();
		int j;
		bool ok=true;
		for(j=0;i+j<n;j++)
		{
			if(s[i+j]!=s[j])
			{
//				cout<<"ZHI\n";
				ok=false;
				break;
			}
		}
		j--;
//		cout<<j<<endl;
		if(ok==true)
		{
//			cout<<ok<<endl;
			ans.clear();
			for(int k=j+1;k<n;k++)
			{
				ans+=s[k];
//				cout<<k<<" "<<ans<<"\n";
			}
//			cout<<ans<<endl;
		}
	}
//	cout<<ans<<"\n";
	cout<<s;
	for(int i=2;i<=m;i++)
	{
		cout<<ans;
	}
	cout<<"\n";
	return 0;
}