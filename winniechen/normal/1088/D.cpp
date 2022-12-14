#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
int n,m,ans1,ans2;
int ask(int a,int b)
{
	cout<<"? "<<a<<" "<<b<<endl;
	int opt;cin>>opt;return opt;
} 
int main()
{
	int sta=ask(0,0);
	for(int i=29;i>=0;i--)
	{
		int k=ask(ans1|(1<<i),ans2|(1<<i));
		if(k==sta)
		{
			if(ask(ans1^(1<<i),ans2)==-1) ans1|=(1<<i),ans2|=(1<<i);
		} 
		else
		{
			if(k==0)
			{
				if(sta==1) ans2|=(1<<i);
				else ans1|=(1<<i); sta=0;
			}
			else
			{
				if(k==1) ans2|=(1<<i);
				else ans1|=(1<<i);
				sta=ask(ans1,ans2);
			}
		}
	}
	cout<<"! "<<ans1<<" "<<ans2<<endl;
	return 0;
}