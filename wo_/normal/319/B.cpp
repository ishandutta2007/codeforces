#include<cstdio>
#include<set>

using namespace std;

set<int> se;

int a[100100];
int ids[100100];
int le[100100];

struct RMQ{
	int N;
	int dat[262144];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=1;i<=N*2-1;i++) dat[i]=-1;
	}
	void update(int id,int x)
	{
		id+=N;
		while(id>0)
		{
			dat[id]=max(dat[id],x);
			id/=2;
		}
	}
	int get(int l,int r,int k,int a,int b)
	{
		if(l<=a&&b<=r) return dat[k];
		if(r<=a||b<=l) return -1;
		return max(get(l,r,k*2,a,(a+b)/2),get(l,r,k*2+1,(a+b)/2,b));
	}
	int get(int l,int r)
	{
		if(l==r) return 0;
		return get(l,r,1,0,N);
	}
};

RMQ rmq;

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	for(int i=0;i<N;i++)
	{
		a[i]--;
		ids[a[i]]=i;
	}
	se.insert(-1);
	se.insert(N+1);
	for(int i=N-1;i>=0;i--)
	{
		set<int>::iterator it=se.lower_bound(ids[i]);
		it--;
		le[ids[i]]=*it;
		se.insert(ids[i]);
	}
	rmq.init(N);
	for(int i=0;i<N;i++)
	{
		if(le[i]==-1) rmq.update(i,0);
		else
		{
			int id=le[i];
			int Ma=rmq.get(id+1,i);
			//printf("%d %d %d\n",i,id,Ma);
			rmq.update(i,Ma+1);
		}
	}
	printf("%d\n",rmq.get(0,N));
	return 0;
}