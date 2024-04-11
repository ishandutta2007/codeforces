
 #include<cstdio>
#include<queue>
#include<utility>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

int cand[100100];

struct task{
	long long t,s,p;
	int id;
	task(){}
	task(int a,int b,int c,int d):t(a),s(b),p(c),id(d){}
};

bool cmp(const task &t1,const task &t2)
{
	return t1.t<t2.t;
}

task tasks[50000];

int hp;
long long ans[50000];

priority_queue<P> que;

map<int,int> mp;

long long fin;

set<int> se;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int N;
	bool ap=false;
	scanf("%d",&N);
	int pid=-1;
	for(int i=0;i<N;i++)
	{
		int t,s,p;
		scanf("%d%d%d",&t,&s,&p);
		if(p==-1)
		{
			ap=true;
			pid=i;
		}
		tasks[i]=task(t,s,p,i);
		if(p!=-1)
		{
			cand[(i+(ap?-1:0))*2]=p-1;
			cand[(i+(ap?-1:0))*2+1]=p+1;
			mp[p]=i;
			se.insert(p);
		}
	}
	cin>>fin;
	for(int i=0;i<2*N-2;i++) if(se.find(cand[i])!=se.end()) cand[i]=(int)(1e9)+1;
	sort(cand,cand+2*N-2);
	int cln=unique(cand,cand+2*N-2)-cand;
	if(cand[cln-1]==(int)(1e9)+1) cln--;
	sort(tasks,tasks+N,cmp);
	int xid=-1;
	for(int i=0;i<N;i++) if(tasks[i].p==-1) xid=i;
	int lb=0,ub=cln;
	while(ub-lb>1)
	{
		int mid=(ub+lb)/2;
		int tmp=cand[mid];
		tasks[xid].p=tmp;
		mp[tmp]=pid;
		int prev=0;
		long long res=0;
		for(int i=0;i<N;i++)
		{
			long long m=tasks[i].t-prev;
			long long total=0;
			while(!que.empty()&&total<m)
			{
				P p=que.top();
				que.pop();
				if(total+p.second<=m)
				{
					if(p.first==tmp)
					{
						res=(long long)prev+total+p.second;
					}
					total+=p.second;
					ans[mp[p.first]]=prev+total;
				}
				else
				{
					long long cando=m-total;
					p.second-=cando;
					que.push(p);
					break;
				}
			}
			prev=tasks[i].t;
			que.push(P(tasks[i].p,tasks[i].s));
		}
		long long total=0;
		while(!que.empty())
		{
			P p=que.top();
			que.pop();
			if(p.first==tmp)
			{
				res=prev+total+p.second;
			}
			total+=p.second;
			ans[mp[p.first]]=prev+total;
		}
		if(res>=fin) lb=mid;
		else ub=mid;
	}
	cout<<cand[lb]<<"\n";
		//int mid=(ub+lb)/2;
		int mid=lb;
		int tmp=cand[mid];
		tasks[xid].p=tmp;
		mp[tmp]=pid;
		int prev=0;
		long long res=0;
		for(int i=0;i<N;i++)
		{
			long long m=tasks[i].t-prev;
			long long total=0;
			while(!que.empty()&&total<m)
			{
				P p=que.top();
				que.pop();
				if(total+p.second<=m)
				{
					if(p.first==tmp)
					{
						res=(long long)prev+total+p.second;
					}
					total+=p.second;
					ans[mp[p.first]]=prev+total;
				}
				else
				{
					long long cando=m-total;
					p.second-=cando;
					que.push(p);
					break;
				}
			}
			prev=tasks[i].t;
			que.push(P(tasks[i].p,tasks[i].s));
		}
		long long total=0;
		while(!que.empty())
		{
			P p=que.top();
			que.pop();
			if(p.first==tmp)
			{
				res=prev+total+p.second;
			}
			total+=p.second;
			ans[mp[p.first]]=prev+total;
		}

	for(int i=0;i<N;i++)
	{
		cout<<ans[i]<<(i==N-1?'\n':' ');
	}
	return 0;
}