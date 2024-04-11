#include<cstdio>
#include<vector>
#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int a[300300];

long long sum[300300];

map<int,int> Mid,mid;

vector<int> vec;

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",a+i+1);
	sum[0]=0;
	for(int i=1;i<=N;i++)
	{
		sum[i]=sum[i-1]+(a[i]>0?a[i]:0);
	}
	for(int i=1;i<=N;i++)
	{
		int num=a[i];
		if(Mid.count(num)==0)
		{
			Mid[num]=i;
			mid[num]=i;
		}
		else
		{
			Mid[num]=i;
		}
	}
	int l=-1,r=-1;
	long long res=-(1ll<<50);
	for(int i=1;i<=N;i++)
	{
		int num=a[i];
		if(Mid[num]==i) continue;
		int tl=i,tr=Mid[num];
		long long tmp=num*2;
		long long msum=sum[tr-1]-sum[tl];
		if(msum+tmp>res)
		{
			l=tl,r=tr;
			res=msum+tmp;
		}
	}
	int cnt=(l-1)+(N-r);
	for(int i=l+1;i<r;i++)
	{
		if(a[i]<0) cnt++;
	}
	for(int i=1;i<l;i++) vec.push_back(i);
	for(int i=l+1;i<r;i++) if(a[i]<0) vec.push_back(i);
	for(int i=r+1;i<=N;i++) vec.push_back(i);
	cout<<res<<" "<<cnt<<"\n";
	for(int i=0;i<vec.size();i++) printf("%d%c",vec[i],i+1==vec.size()?'\n':' ');
	return 0;
}