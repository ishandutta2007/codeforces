#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m=0,k=0;
	string s;
	cin>>n>>s;
	for(int i=1;i<=n/2;i++)
	if(s[i-1]=='R')
	cout<<n/2+i<<" "<<i<<endl;
	else
	cout<<i<<" "<<n/2+i<<endl;
}