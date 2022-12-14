#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>

using namespace std;

struct RMQ{
	int N;
	int dat[540540];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=0;i<=2*N-1;i++)
		{
			dat[i]=0;
		}
	}
	void update(int i,int x)
	{
		if(dat[i+N]>=x) return;
		i+=N;
		dat[i]=x;
		while(i>1)
		{
			i/=2;
			dat[i]=max(dat[i],x);
		}
	}
	int query(int a,int b,int k,int l,int r)
	{
		if(a<=l&&r<=b) return dat[k];
		if(b<=l||r<=a) return 0;
		int Ml=query(a,b,k*2,l,(l+r)/2);
		int Mr=query(a,b,k*2+1,(l+r)/2,r);
		return max(Ml,Mr);
	}
	int query(int a,int b)
	{
		return query(a,b,1,0,N);
	}
};

struct obj{
	int l,r,t;
	bool which;//true:bus,false:person
	int id;
	obj(){}
	obj(int a,int b,int c,bool d,int e):l(a),r(b),t(c),which(d),id(e){}
};

bool cmp(const obj &o1,const obj &o2)
{
	if(o1.l!=o2.l) return o1.l<o2.l;
	if(o1.r!=o2.r) return o1.r>o2.r;
	if(o1.which==true&&o2.which==false) return true;
	return false;
}

RMQ rmq;
vector<obj> objs;
vector<int> times;
map<int,int> busid;//[bus time]=bus id

int ans[100100];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		//buses
		int s,f,t;
		scanf("%d%d%d",&s,&f,&t);
		objs.push_back(obj(s,f,t,true,i));
		times.push_back(t);
		busid[t]=i;
	}
	for(int i=0;i<M;i++)
	{
		//people
		int l,r,b;
		scanf("%d%d%d",&l,&r,&b);
		objs.push_back(obj(l,r,b,false,i));
		times.push_back(b);
	}
	sort(times.begin(),times.end());
	times.erase(unique(times.begin(),times.end()),times.end());
	memset(ans,-1,sizeof(ans));
	rmq.init(times.size());
	sort(objs.begin(),objs.end(),cmp);
	for(int i=0;i<objs.size();i++)
	{
		//printf("%d %d %d\n",objs[i].l,objs[i].r,objs[i].t);
		if(objs[i].which==true)//bus
		{
			int t=objs[i].t;
			int tid=distance(times.begin(),lower_bound(times.begin(),times.end(),t));
			//printf("bus::%d %d\n",tid,objs[i].r);
			rmq.update(tid,objs[i].r);
		}
		else
		{
			int id=objs[i].id;
			int r=objs[i].r;
			int t=objs[i].t;
			int tid=distance(times.begin(),lower_bound(times.begin(),times.end(),t));
			int NN=rmq.N;
			int best=rmq.query(tid,NN);
			//printf("person::%d %d\n",tid,r);
			if(best<r)
			{
				ans[id]=-1;
				continue;
			}
			int lb=tid-1,ub=NN;
			while(ub-lb>1)
			{
				int mid=(lb+ub)/2;
				//printf("rmq::%d %d %d\n",tid,mid+1,rmq.query(tid,mid+1));
				if(rmq.query(tid,mid+1)>=r)
				{
					ub=mid;
				}
				else
				{
					lb=mid;
				}
			}
			//printf("%d\n",ub);
			int bus_time=times[ub];
			ans[id]=busid[bus_time];
		}
	}
	for(int i=0;i<M;i++)
	{
		printf("%d%c",ans[i],i==M-1?'\n':' ');
	}
	return 0;
}