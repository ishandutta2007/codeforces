#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int N,M,S;
	scanf("%d%d%d",&N,&M,&S);
	long long ans=0;
	for(int h=0;h<=(N/2);h++)
	{
		for(int w=0;w<=(M/2);w++)
		{
			int H=h*2+1,W=w*2+1;
			if(H>N||W>M) continue;
			if(H*W>S) continue;
			else if(H*W==S)
			{
				long long a=(N-H+1)*(M-W+1);
				long long b=(h+1)*(w+1);
				ans+=max(0ll,a*b*2-a);
			}
			else
			{
				int rem=S-(H*W);
				for(int hh=0;hh<h;hh++)
				{
					int H2=hh*2+1;
					if(H2>N) continue;
					if(rem%H2!=0) continue;
					int ww=rem/H2;
					if(ww%2!=0) continue;
					int TH=H,TW=W+ww;
					long long a=(N-TH+1)*(M-TW+1);
					ans+=max(a*2,0ll);
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}