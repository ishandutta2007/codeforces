#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<long long,long long> P;

const long long inf=1ll<<50;
/*
struct RMQ{
	int N;
	long long dat[262144];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=1;i<=N*2-1;i++) dat[i]=-inf;
	}
	void update(int i,long long x)
	{
		i+=N;
		while(i>0)
		{
			dat[i]=max(dat[i],x);
			i/=2;
		}
	}
	long long query(int l,int r,int k,int a,int b)
	{
		if(l<=a&&b<=r) return dat[k];
		if(r<=a||b<=l) return -inf;
		return max(query(l,r,k*2,a,(a+b)/2),query(l,r,k*2+1,(a+b)/2,b));
	}
	long long query(int l,int r)
	{
		return query(l,r,1,0,N);
	}
};

RMQ rmq,rMq;*/

long long min_from_right[100100],max_from_right[100100];
long long min_from_left[100100],max_from_left[100100];
int N;

long long left_min(int id)
{
	if(id==0) return inf;
	else return min_from_left[id-1];
}
long long left_max(int id)
{
	if(id==0) return -inf;
	else return max_from_left[id-1];
}
long long right_min(int id)
{
	if(id==N) return inf;
	return min_from_right[id];
}
long long right_max(int id)
{
	if(id==N) return -inf;
	return max_from_right[id];
}

int xs[100100],ys[100100];
P ps[100100];
long long xx[100100],yy[100100];

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",xs+i,ys+i);
		xs[i]*=2,ys[i]*=2;
		ps[i]=P((long long)xs[i]+ys[i],(long long)xs[i]-ys[i]);
	}
	sort(ps,ps+N);
	for(int i=0;i<N;i++)
	{
		xx[i]=ps[i].first,yy[i]=ps[i].second;
	}/*
	rmq.init(N);
	rMq.init(N);
	for(int i=0;i<N;i++)
	{
		rmq.update(i,-yy[i]);
		rMq.update(i,yy[i]);
	}*/
	for(int i=0;i<N;i++)
	{
		min_from_left[i]=inf;
		max_from_left[i]=-inf;
		min_from_right[i]=inf;
		max_from_right[i]=-inf;
	}
	min_from_left[0]=yy[0];
	max_from_left[0]=yy[0];
	for(int i=1;i<N;i++)
	{
		min_from_left[i]=min(min_from_left[i-1],yy[i]);
		max_from_left[i]=max(max_from_left[i-1],yy[i]);
	}
	min_from_right[N-1]=yy[N-1];
	max_from_right[N-1]=yy[N-1];
	for(int i=N-2;i>=0;i--)
	{
		min_from_right[i]=min(min_from_right[i+1],yy[i]);
		max_from_right[i]=max(max_from_right[i+1],yy[i]);
	}
	long long ub=8000000000ll,lb=-1;
	while(ub-lb>1)
	{
		long long mid=(ub+lb)/2;
		int s=0,t=0;
		if(ps[N-1].first-ps[0].first<=mid*2)
		{
			ub=mid;
			continue;
		}
		bool ok=false;
		while(s<N)
		{
			while(t<N)
			{
				if(t==N||xx[t]-xx[s]>mid*2) break;
				t++;
			}
			//long long M=max(rMq.query(0,s),rMq.query(t,N));
			//long long m=-max(rmq.query(0,s),rmq.query(t,N));
			long long M=max(left_max(s),right_max(t));
			long long m=min(left_min(s),right_min(t));
			if(M-m<=mid*2)
			{
				ok=true;
				break;
			}
			s++;
		}
		if(ok) ub=mid;
		else lb=mid;
	}
	printf("%.9f\n",(double)ub/2);
	return 0;
}