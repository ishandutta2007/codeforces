#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int a,b,t;
	cin>>a>>b;
	if(a<b) t=a,a=b,b=t;
	a-=b;
	cout<<b<<" "<<a/2;
	return 0;
}