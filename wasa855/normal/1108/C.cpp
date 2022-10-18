#include<bits/stdc++.h>
using namespace std;
string ans;
int n;
string s;
int data=200005;
void comp(string x)
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(x[i%3]!=s[i])
		{
			res++;
		}
	}
	if(res<data)
	{
		data=res;
		ans=x;
	}
}
int main()
{
	cin>>n;
	cin>>s;
	comp("RGB");
	comp("RBG");
	comp("BGR");
	comp("BRG");
	comp("GBR");
	comp("GRB");
	cout<<data<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<ans[i%3];
	}
	cout<<"\n";
	return 0;
}