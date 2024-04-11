#include<cstdio>
#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

const int inf=1100100100;

//typedef pair<int,int> P;

//P reach_time[100100];
int times[100100];
int tln;
int period;
int N,G,R;
long long time_to_dest[100100];

struct RMQ{
	int N;
	int dat[262144];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=1;i<=N*2-1;i++) dat[i]=inf;
	}
	void update(int i,int x)
	{
		i+=N;
		while(i>0)
		{
			dat[i]=min(dat[i],x);
			i/=2;
		}
	}
	int query(int l,int r,int k,int a,int b)
	{
		if(r<=a||b<=l) return inf;
		if(l<=a&&b<=r) return dat[k];
		return min(query(l,r,k*2,a,(a+b)/2),query(l,r,k*2+1,(a+b)/2,b));
	}
	int query(int l,int r)
	{
		if(l==r) return inf;
		return query(l,r,1,0,N);
	}
};

RMQ rmq;

int L[100100];
long long total[100100];

int get(int l,int r)
{
	//l,r are in [0,period)
	int ll=lower_bound(times,times+tln,l)-times;
	int rr=lower_bound(times,times+tln,r)-times;
	if(l<r)
	{
		return rmq.query(ll,rr);
	}
	return min(rmq.query(ll,tln),rmq.query(0,rr));
}

int main()
{
	scanf("%d%d%d",&N,&G,&R);
	period=G+R;
	for(int i=0;i<N+1;i++)
	{
		scanf("%d",L+i);
		if(i==0) total[i]=L[i];
		else total[i]=total[i-1]+L[i];
		if(i!=N)
		{
			int t=total[i]%period;
//			reach_time[i]=P(t,i);
			times[i]=t;
		}
	}
//	sort(reach_time,reach_time+N);
	sort(times,times+N);
	tln=unique(times,times+N)-times;
	rmq.init(tln);
	for(int i=N-1;i>=0;i--)
	{
		long long l=(long long)G+total[i];
		long long r=l+R;
		l%=period;
		r%=period;
		int id=get(l,r);
		if(id==inf)
		{
			//no waiting time
			time_to_dest[i]=total[N]-total[i];
		}
		else
		{
			long long dis=total[id]-total[i];
			dis/=period;
			dis++;
			dis*=period;
			dis+=time_to_dest[id];
			time_to_dest[i]=dis;
		}
		long long tmp=total[i]%period;
		int id2=lower_bound(times,times+tln,tmp)-times;
		rmq.update(id2,i);
	}
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		int T;
		scanf("%d",&T);
		int l=(G-T)%period;
		if(l<0) l+=period;
		int r=(G+R-T)%period;
		if(r<0) r+=period;
		int id=get(l,r);
		if(id==inf)
		{
			long long ans=T+total[N];
			cout<<ans<<"\n";
			continue;
		}
		long long ans=T+total[id];
		ans/=period;
		ans++;
		ans*=period;
		ans+=time_to_dest[id];
		cout<<ans<<"\n";
	}
	return 0;
}