#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
const int mod=1e9+7;
const int N=10050;
struct Matrix
{
	int a[3][3];
	Matrix(){ for(int i=0;i<3;i++) for(int j=0;j<3;j++) a[i][j]=0;}
	Matrix operator * (Matrix b) const
	{
		Matrix c;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					c.a[i][j]+=(ll)a[i][k]*b.a[k][j]%mod;
					if(c.a[i][j]>=mod) c.a[i][j]-=mod;
				}
			}
		}
		return c;
	}
	void id(){ Matrix();for(int i=0;i<3;i++) a[i][i]=1;}
};
Matrix pow(Matrix x, ll k)
{
	Matrix ret;ret.id();
	for(;k;k>>=1,x=x*x) if(k&1) ret=ret*x;
	return ret;
}
int Block[3];
struct Event
{
	int t,k;ll x;
	Event(int a, ll b, int c){ t=a,x=b,k=c;}
	bool operator < (Event b) const { return x<b.x;}
};
vector<Event> events;
int v[3],u[3];
int main()
{
	int n,i,k,j;
	ll m,l,r;
	scanf("%i %lld",&n,&m);
	while(n--) scanf("%i %lld %lld",&k,&l,&r),events.pb(Event(1,l,k-1)),events.pb(Event(-1,r+1,k-1));
	events.pb(Event(0,2,0));
	events.pb(Event(0,m+1,0));
	Matrix f;
	v[1]=1;
	sort(events.begin(),events.end());
	ll time,last=2;
	for(i=0;i<events.size();i++)
	{
		time=events[i].x-last;
		last=events[i].x;
		if(time==0)
		{
			if(events[i].t==-1) Block[events[i].k]--;
			else if(events[i].t==1) Block[events[i].k]++;
			continue;
		}
		if(Block[0] && Block[1] && Block[2]) return printf("0\n"),0;
		if(!Block[0] && !Block[1] && !Block[2])
		{
			f=Matrix();
			f.a[0][0]=1;
			f.a[0][1]=1;
			f.a[0][2]=0;
			f.a[1][0]=1;
			f.a[1][1]=1;
			f.a[1][2]=1;
			f.a[2][0]=0;
			f.a[2][1]=1;
			f.a[2][2]=1;
		}
		else if(!Block[0] && !Block[1] && Block[2])
		{
			f=Matrix();
			f.a[0][0]=1;
			f.a[0][1]=1;
			f.a[1][0]=1;
			f.a[1][1]=1;
		}
		else if(!Block[0] && Block[1] && !Block[2])
		{
			f=Matrix();
			f.a[0][0]=1;
			f.a[2][2]=1;
		}
		else if(Block[0] && !Block[1] && !Block[2])
		{
			f=Matrix();
			f.a[1][1]=1;
			f.a[1][2]=1;
			f.a[2][1]=1;
			f.a[2][2]=1;
		}
		else if(Block[0] && Block[1] && !Block[2])
		{
			f=Matrix();
			f.a[2][2]=1;
		}
		else if(Block[0] && !Block[1] && Block[2])
		{
			f=Matrix();
			f.a[1][1]=1;
		}
		else if(!Block[0] && Block[1] && Block[2])
		{
			f=Matrix();
			f.a[0][0]=1;
		}
		u[0]=(v[0]+v[1])%mod;
		u[1]=(u[0]+v[2])%mod;
		u[2]=(v[1]+v[2])%mod;
		if(Block[0]) u[0]=0;
		if(Block[1]) u[1]=0;
		if(Block[2]) u[2]=0;
		for(j=0;j<3;j++) v[j]=u[j];
		f=pow(f,time-1);
		for(j=0;j<3;j++)
		{
			u[j]=0;
			for(k=0;k<3;k++)
			{
				u[j]+=(ll)v[k]*f.a[j][k]%mod;
				if(u[j]>=mod) u[j]-=mod;
			}
		}
		for(j=0;j<3;j++) v[j]=u[j];
		//printf("Time %lld\n",events[i].x);
		//for(j=0;j<3;j++) printf("%i ",v[j]);
		//printf("\n");
		//printf("Block\n");
		//for(j=0;j<3;j++) printf("%i ",Block[j]);
		//printf("\n");
		if(events[i].t==-1) Block[events[i].k]--;
		else if(events[i].t==1) Block[events[i].k]++;
	}
	printf("%i\n",v[1]);
	return 0;
}