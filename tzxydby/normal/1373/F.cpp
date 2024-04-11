#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int a[N],b[N],n,t;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int x=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			x+=a[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			x-=b[i];
		}
		int y=0,fl=1;
		for(int i=1;i<n*2;i++)
		{
			y=max(0ll,y)+a[i%n]-b[(i-1)%n];
			if(y>b[i%n])
				fl=0;
		}
		cout<<(fl&&x<=0?"YES":"NO")<<endl;
	}
	return 0;
}