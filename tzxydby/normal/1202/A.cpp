#include<bits/stdc++.h>
using namespace std;
const int N=100005;
string s,t;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>s>>t;
		int n=s.size(),m=t.size(),k=0;
		for(int i=m-1;i>=0;i--)
		{
			if(t[i]=='1')
			{
				k=m-i;
				break;
			}	
		} 
		int flag=0;
		for(int i=n-k;i>=0;i--)
		{
			if(s[i]=='1')
			{
				cout<<n-i-k<<endl;
				flag=1;
				break;
			}
		}
		if(!flag)
			cout<<n<<endl;
	}
	return 0;
}