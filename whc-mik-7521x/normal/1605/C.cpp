#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		int ans = -1;
		for(int i=0;i<s.size();++i)
		  {
		  	 if(s[i]!='a') continue;
		  	 int ca = 1 ;
		  	 int cb = 0 ;
		  	 int cc = 0 ;
		  	 for(int j=1;j<=9&&i+j<s.size();++j)
		  	 {
		  	 	if(s[i+j]=='a') ca++;
		  	 	if(s[i+j]=='b') cb++;
		  	 	if(s[i+j]=='c') cc++;
		  	 	if(ca>cb&&ca>cc) {if(ans==-1) ans = j+1; else ans=min(ans,j+1);}
			 }
		  }
		cout<<ans<<endl;
	}
}