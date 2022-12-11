#include<bits/stdc++.h>
using namespace std;
int n;
inline long long query(int l,int r)
{
	assert(1<=l&&l<=r&&r<=n);
	printf("? %d %d\n",l,r);
	fflush(stdout);
	long long x;
	scanf("%lld",&x);
	assert(x!=-1);
	return x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long long tot=query(1,n);
		int L=1,R=n;
		bool flag_over=false;
		while(R-L+1>4)
		{
			int mid=(L+R)>>1;
			long long cnt=query(1,mid);
			if(!cnt)
				L=mid;
			else if(cnt==tot)
				R=mid;
			else
			{
				long long c=query(1,mid+1);
				int pos=mid-(c-cnt)+1;
				if(!query(1,pos))
				{
					int i=pos;
					int k=n;
					while(L<=R)
					{
						int mid=(L+R)>>1;
						if(!query(mid,n))
							k=mid,R=mid-1;
						else
							L=mid+1;
					}
					L=k-i+1; // 
					long long prod=L*(L-1ll)/2-tot;
					int x=(L+sqrt(1ll*L*L-4*prod))*0.5;
					if(x-1>=2&&(x-1ll)*(L-(x-1))==prod)
						--x;
					else if(x+1<=L-2&&(x+1ll)*(L-(x+1))==prod)
						++x;
					x=max(x,L-x);
					int j;
					if(query(i,i+x-1)==x*(x-1ll)/2)
						j=i+x;
					else
						j=k-x+1;
					printf("! %d %d %d\n",i,j,k);
					fflush(stdout);
				}
				else
				{
					int j=pos;
					int k=n;
					while(L<=R)
					{
						int mid=(L+R)>>1;
						if(!query(mid,n))
							k=mid,R=mid-1;
						else
							L=mid+1;
					}
					long long cnt=tot-(k-j+1ll)*(k-j)/2;
					L=ceil(sqrt(2*cnt));
					int i=j-L;
					printf("! %d %d %d\n",i,j,k);
					fflush(stdout);
				}
				flag_over=true;
				break;
			}
		}
		if(!flag_over)
		{
			assert(R-L+1==4);
			printf("! %d %d %d\n",L,L+2,L+3);
			fflush(stdout);
		}
	}
	return 0;
}