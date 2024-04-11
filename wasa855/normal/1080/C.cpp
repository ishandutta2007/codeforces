#include<bits/stdc++.h>
using namespace std;
#define int long long
void work()
{
	int n,m;
	cin>>n>>m;
	int b=n*m/2,w=n*m/2;
	if(n%2==1&&m%2==1)
	{
		w++;
	}
	int l1,r1,L1,R1;
	cin>>l1>>r1>>L1>>R1;
	int c=(L1-l1+1)*(R1-r1+1)/2;
	if((L1-l1+1)%2==1&&(R1-r1+1)%2==1&&(l1%2)!=(r1%2))
	{
		c++;
	}
	b-=c;
	w+=c;
	int l2,r2,L2,R2;
	cin>>l2>>r2>>L2>>R2;
	c=(L2-l2+1)*(R2-r2+1)/2;
	if((L2-l2+1)%2==1&&(R2-r2+1)%2==1&&(l2%2)==(r2%2))
	{
		c++;
	}
	b+=c;
	w-=c;
	int x1=max(l1,l2),y1=max(r1,r2),x2=min(L1,L2),y2=min(R1,R2);
	if((x2-x1+1)>0&&(y2-y1+1)>0)
	{
		c=(x2-x1+1)*(y2-y1+1)/2;
		if(((x2-x1+1)%2==1)&&((y2-y1+1)%2==1)&&((x1%2)!=(y1%2)))
		{
			c++;
		}
		b+=c;
		w-=c;
	}
	cout<<w<<" "<<b<<"\n";
}
signed main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		work();
	}
	return 0;
}