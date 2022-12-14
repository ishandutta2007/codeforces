#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

long long h[1001000],p[100100];
int N,M;

long long t;
int get(int init,int leftid)
{
	long long s=h[init];
	long long left=p[leftid];
	long long t1=left-s;
	if(t1<0) t1*=-1;
	if(t1>t) return -1;
	long long t2=t-t1;
	long long right=max(s,left+t2);
	int id=lower_bound(p,p+M,right+1)-p;
	if(s<=left) return id-1;
	long long rem=t-(s-left);
	rem/=2;
	long long right2=s+rem;
	int id2=lower_bound(p,p+M,right2+1)-p;
	return max(id,id2)-1;
}

bool check()
{
	int id=0;
	for(int i=0;i<N;i++)
	{
		int id2=get(i,id);
		if(id2==-1) continue;
		id=id2+1;
		if(id==M) return true;
	}
	return false;
}

int main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++) cin>>h[i];
	for(int i=0;i<M;i++) cin>>p[i];
	long long ub=1ll<<45,lb=-1;
	while(ub-lb>1)
	{
		t=(ub+lb)/2;
		if(check())
		{
			ub=t;
		}
		else
		{
			lb=t;
		}
	}
	cout<<ub<<"\n";
	return 0;
}