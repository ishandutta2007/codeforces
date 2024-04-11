#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
const int M=1024*256;

struct task
{
	int cost, time, ind, costind;
};

int n;
LL tim;
PLL PT[150005];
task T[150005];
vector<PII> V;
PII B[150005];
double D[2*M];

bool cmp(task a, task b)
{
	if((LL)a.cost*b.time==(LL)a.time*b.cost)
	{
		if(a.cost==b.cost)
			return a.ind<b.ind;
		return a.cost<b.cost;
	}
	return (LL)a.cost*b.time>(LL)a.time*b.cost;
}

double getscore(int ind, double c, LL tajm)
{
	return (double)T[ind].cost*(1.0-c*((double)tajm/(double)tim));
}

void add(int v, double x)
{
	v+=M;
	D[v]=max(D[v], x);
	while(v>1)
	{
		v/=2;
		D[v]=max(D[2*v], D[2*v+1]);
	}
}

double maxi(int st, int en)
{
	st+=M;
	en+=M;
	double r=max(D[st], D[en]);
	while(st/2!=en/2)
	{
		if(st%2==0)
			r=max(r, D[st+1]);
		if(en%2==1)
			r=max(r, D[en-1]);
		st/=2;
		en/=2;
	}
	return r;
}

bool solve(double c)
{
	for(int i=0; i<n; i++)
	{
		double x=getscore(i, c, PT[i].F), y=getscore(i, c, PT[i].S);
		if(maxi(0, T[i].costind-1)>y)
			return false;
		add(T[i].costind, x);
	}
	return true;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		T[i].cost=a;
		T[i].ind=i;
		V.PB(MP(a, i));
	}
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		T[i].time=a;
	}
	sort(V.begin(), V.end());
	int prev=-1, tmp=0;
	for(int i=0; i<n; i++)
	{
		if(V[i].F!=prev)
		{
			prev=V[i].F;
			tmp++;
		}
		T[V[i].S].costind=tmp;
	}
	sort(T, T+n, cmp);
	int lef=0, rig=0;
	for(int i=0; i<n; i++)
	{
		tim+=T[i].time;
		if(i<n-1 && (LL)T[i].cost*T[i+1].time==(LL)T[i].time*T[i+1].cost)
			rig++;
		else
		{
			for(int j=lef; j<=rig; j++)
			{
				B[j]=MP(lef, rig);
				PT[j]=MP(T[j].time, tim);
				if(lef>0)
					PT[j].F+=PT[lef-1].S;
			}
			lef=i+1;
			rig=i+1;
		}
	}
	/*for(int i=0; i<n; i++)
	{
		printf("%d %d %d %d\n", B[i].F, B[i].S, PT[i].F, PT[i].S);
	}*/
	double st=0, en=1, mid=(st+en)/2, res=0;
	for(int i=0; i<40; i++)
	{
		for(int i=0; i<2*M; i++)
			D[i]=0;
		if(solve(mid))
		{
			res=max(res, mid);
			st=mid;
		}
		else
			en=mid;
		mid=(st+en)/2;
	}
	printf("%.7lf\n", res);
	return 0;
}