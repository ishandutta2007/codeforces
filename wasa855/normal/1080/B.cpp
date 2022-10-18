#include<bits/stdc++.h>
using namespace std;
void work()
{
	int l,r;
	cin>>l>>r;
	int L=l-l%2;
	int R=r-r%2+1;
	int ans=-(R-L+1)/2;
	if(L!=l)
	{
		ans-=L;
	}
	if(R!=r)
	{
		ans+=R;
	}
	cout<<ans<<endl;
}
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		work();
	}
	return 0;
}