#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
	cin>>t;
	while(t--)
		for(int i=1,f=1;f;i=i%8+1)
			for(int j=1;j<=8&&f;j++)
				cout<<i<<' '<<((i&1)?j:9-j)<<endl,cin>>s,f=(s!="Done");
	return 0;
}