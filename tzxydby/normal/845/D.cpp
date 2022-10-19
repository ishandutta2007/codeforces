#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	vector<int>v;
	v.clear();
	int n,x,sp,y,ans=0,ot=0;
	cin>>n;
	while(n--)
	{
		cin>>x;
		if(x==1)
			cin>>sp;
		else if(x==2) 
			ans+=ot,ot=0;
		else if(x==3) 
			cin>>y,v.push_back(y);
		else if(x==4) 
			ot=0;
		else if(x==5) 
			v.clear();
		else 
			ot++;
		while(!v.empty()&&v.back()<sp) 
			v.erase(--v.end()),ans++;
	}
	cout<<ans<<endl;
	return 0;
}