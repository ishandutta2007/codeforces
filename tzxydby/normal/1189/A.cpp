#include<bits/stdc++.h>
using namespace std;
int n,sum;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
		if(s[i]=='1')
			sum++;
	if(sum!=n-sum)
	{
		cout<<1<<endl;
		cout<<s<<endl;
	}
	else
	{
		cout<<2<<endl<<s[0]<<' ';
		for(int i=1;i<n;i++)
			cout<<s[i];
		cout<<endl;
	}
	return 0;
}