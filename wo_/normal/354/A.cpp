#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int w[100100];
int sum[100100];
int L,R;
int QL,QR;
int N;

int main()
{
	scanf("%d",&N);
	scanf("%d%d%d%d",&L,&R,&QL,&QR);
	sum[0]=0;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",w+i);
		sum[i]=sum[i-1]+w[i];
	}
	long long ans=1ll<<50;
	for(int x=1;x<N;x++)
	{
		int y=N-x;
		long long le=sum[x]-sum[0];
		le*=L;
		long long ri=sum[N]-sum[x];
		ri*=R;
		long long tmp=le+ri;
		tmp+=(max(0,x-y-1)*QL);
		tmp+=(max(0,y-x-1)*QR);
		ans=min(ans,tmp);
	}
	
	long long all_le=sum[N]*L;
	all_le+=QL*(N-1);
	ans=min(ans,all_le);
	
	long long all_ri=sum[N]*R;
	all_ri+=QR*(N-1);
	ans=min(ans,all_ri);
	
	cout<<ans<<"\n";
	return 0;
}