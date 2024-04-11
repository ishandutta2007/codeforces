#include <bits/stdc++.h>
using namespace std;
bool p(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)	return false;
	}
	return true;
}
int main(void)
{
	int n,cur=0;
	cin>>n;
	int prime[5100];
	for(int i=2;i<n;i++)
	{
		if(p(i))
		{
			prime[cur]=i;
			cur++;
		}
	}
	int num=0,ans=0;
	for(int i=1;i<=n;i++)
	{
        num=0;
        for(int j=0;j<n;j++)
		{
            if(prime[j]==0)break;
            else if(i%(prime[j])==0){num++;}
        }
        if(num==2)	ans++;
    }
    cout<<ans<<endl;
    return 0;
}