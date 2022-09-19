#include <bits/stdc++.h> 

using namespace std;
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t;
	cin>>t;
	while(t--) 
	{
		int n;
		cin>>n;
		string s;
		cin>>s; 
		{
			pair <int,int> u[n/2];
			int c00=0,c01=0,c11=0;
			bool mid=0;
			if(n%2==1 && s[n/2]=='0') mid=1;
			for(int i=0;i<n/2;++i) 
			{
				u[i]={s[i]-'0',s[n-i-1]-'0'};
				if(u[i].first+u[i].second==1) c01++;
		        else if(u[i].first+u[i].second==0) c00++;
		        else c11++;
			}
			if(!mid) cout<<"BOB"<<'\n';
			else if(c00!=0) cout<<"ALICE"<<'\n';
			else cout<<"BOB"<<'\n';
		}
	}
	return 0;
}