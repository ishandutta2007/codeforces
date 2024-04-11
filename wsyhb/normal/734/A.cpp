#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,s1=0,s2=0,i=1;
	char x;
	cin>>n;
	while(i<=n)
	{
		scanf("%c",&x);
		if(x=='\n') continue;
		if(x=='A') s1++;
		else s2++;
		i++;
	}
	cout<<(s1==s2?"Friendship":(s1>s2?"Anton":"Danik"));
	return 0;
}