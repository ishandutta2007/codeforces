#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long u,v;
	cin>>u>>v;
	if(u==0&&v==0)
		cout<<"0\n";
	else if(u==v)
		cout<<1<<endl<<u<<endl;
	else if(u>v||(v-u)%2)
		cout<<"-1\n";
	else
	{
		long long x=u,y=(v-u)/2;
		if((x+y)==(x^y))
			cout<<2<<endl<<x+y<<' '<<y<<endl;
		else
			cout<<3<<endl<<x<<' '<<y<<' '<<y<<endl;
	}
	return 0;
}