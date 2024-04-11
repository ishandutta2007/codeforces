#include<bits/stdc++.h>
using namespace std;
int main()
{
	set <string> a;
	int n,m;
	cin>>n>>m;
	string s,t,x,mid,ans="";
	while(n--)
	{
		cin>>s;
		t=s;
		reverse(t.begin(),t.end());
		if(s==t) mid=t;
		else if(a.count(t)) ans+=t;
		a.insert(s);
	}
	x=ans;
	reverse(x.begin(),x.end());
	ans+=mid+x;
	cout<<ans.size()<<"\n"<<ans;

}