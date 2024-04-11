#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <map>
using namespace std;
#define ll long long
#define mp make_pair
const ll Max=1000000;
const int N=5250;
struct Point
{
	ll x,y;
	Point(ll a=0, ll b=0){ x=a,y=b;}
	Point operator - (Point b) const { return Point(x-b.x,y-b.y);}
	bool operator < (Point b) const { return y*b.x<b.y*x;}
	bool operator == (Point b) const{ return y*b.x==b.y*x;}
	bool operator != (Point b) const{ return y*b.x!=b.y*x;}
	ll sz(){ return x*x+y*y;}
};
ll gcd(ll x, ll y){ return y?gcd(y,x%y):x;}
struct Q
{
	ll p,q;
	Q(ll a=0, ll b=0){ p=a,q=b;}
	void Cut()
	{
		if(q<0) p=-p,q=-q;
		if(q)
		{
			ll g=gcd(abs(p),abs(q));
			p/=g;
			q/=g;
		}
		else p=0;
	}
	Q operator + (Q b) const
	{
		Q sol;
		sol.p=p*b.q+b.p*q;
		sol.q=q*b.q;
		sol.Cut();
		return sol;
	}
	Q operator - (Q b) const
	{
		Q sol;
		sol.p=p*b.q-b.p*q;
		sol.q=q*b.q;
		sol.Cut();
		return sol;
	}
	Q operator * (ll b) const
	{
		Q sol;
		sol.p=p*b;
		sol.q=q;
		sol.Cut();
		return sol;
	}
	Q operator / (Q b) const
	{
		Q sol;
		sol.p=p*b.q;
		sol.q=q*b.p;
		sol.Cut();
		return sol;
	}
};
Q ans,k;
Point a,b;
void FindSlope()
{
	ans.p=a.y-b.y;
	ans.q=a.x-b.x;
	ans.Cut();
}
void FindIntercept()
{
	ans=Q(a.y,1)-(k*a.x);
}
Point p[4];
Q k1,k2,n1,n2,tmp;
struct Triple
{
	ll x,y,z;
	Triple(ll a, ll b, ll c){ x=a,y=b,z=c;}
};
Triple operator * (Point a, Point b)
{
	return Triple(b.y-a.y,a.x-b.x,a.y*b.x-a.x*b.y);
}
Triple operator * (Triple a, Triple b)
{
	return Triple(a.y*b.z-b.y*a.z,b.x*a.z-a.x*b.z,a.x*b.y-a.y*b.x);
}
bool Find(ll &x, ll &y)
{
	Triple a=p[0]*p[1],b=p[2]*p[3];
	a=a*b;
	if(a.z==0 || a.x%a.z || a.y%a.z) return 0;
	x=a.x/a.z;y=a.y/a.z;
	if(abs(x)>Max || abs(y)>Max) return 0;
	return 1;
	//printf("Points:(%lld, %lld) (%lld, %lld) (%lld, %lld) (%lld, %lld)\n",p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y,p[3].x,p[3].y);
	/*if(p[0].x==p[1].x && p[2].x==p[3].x) return 0;
	if(p[0].x==p[1].x)
	{
		x=p[0].x;
		a=p[2];b=p[3];FindSlope();
		k1=ans;
		k=k1;FindIntercept();
		n1=ans;
		tmp=(k1*x)+n1;
		if(tmp.q!=1) return 0;
		y=tmp.p;
		if(y>Max || y<-Max) return 0;
		return 1;
	}
	if(p[2].x==p[3].x)
	{
		x=p[2].x;
		a=p[0];b=p[1];FindSlope();
		k1=ans;
		k=k1;FindIntercept();
		n1=ans;
		tmp=(k1*x)+n1;
		if(tmp.q!=1) return 0;
		y=tmp.p;
		if(y>Max || y<-Max) return 0;
		return 1;
	}
	a=p[0];b=p[1];FindSlope();
	k1=ans;
	k=k1;FindIntercept();
	n1=ans;
	a=p[2];b=p[3];FindSlope();
	k2=ans;
	k=k2;FindIntercept();
	n2=ans;
	//printf("k1:(%lld/%lld) k2:(%lld/%lld)\n",k1.p,k1.q,k2.p,k2.q);
	//printf("n1:(%lld/%lld) n2:(%lld/%lld)\n",n1.p,n1.q,n2.p,n2.q);
	if(k1.p==k2.p && k1.q==k2.q) return 0;
	tmp=(n1-n2)/(k2-k1);
	//printf("x:(%lld/%lld)\n",tmp.p,tmp.q);
	if(tmp.q!=1) return 0;
	x=tmp.p;
	if(x>Max || x<-Max) return 0;
	tmp=(k1*x)+n1;
	//printf("y:(%lld/%lld)\n",tmp.p,tmp.q);
	if(tmp.q!=1) return 0;
	y=tmp.p;
	if(y>Max || y<-Max) return 0;
	return 1;*/
}
Point P[N],V[N];
int GetRand(int n){ return rand()%n+1;}
int p0,p1,p2,p3;
void Chose(int n)
{
	p0=GetRand(n);
	do{p1=GetRand(n);}while(p1==p0);
	do{p2=GetRand(n);}while(p2==p0 || p2==p1);
	do{p3=GetRand(n);}while(p3==p0 || p3==p1 || p3==p2);
	p[0]=P[p0];
	p[1]=P[p1];
	p[2]=P[p2];
	p[3]=P[p3];
}
bool Check(Point pt, int n)
{
	int i;
	//printf("Check Point (%lld, %lld):\n",pt.x,pt.y);
	for(i=1;i<=n;i++)
	{
		V[i]=P[i]-pt;
		if(V[i].x==0 && V[i].y==0) return 0;
		if(V[i].x<0 || (V[i].x==0 && V[i].y<0)) V[i].x*=-1,V[i].y*=-1;
		//printf("(%lld, %lld) ",V[i].x,V[i].y);
	}
	//printf("\n");
	//printf("Sorted:\n");
	sort(V+1,V+1+n);
	//for(i=1;i<=n;i++) printf("(%lld, %lld) ",V[i].x,V[i].y);printf("\n");
	for(i=1;i<=n;i+=2)
	{
		if(V[i]!=V[i+1]) return 0;
		if(i!=1 && V[i]==V[i-1]) return 0;
	}
	return 1;
}
bool CheckTime()
{
	if(clock()>=4.5*CLOCKS_PER_SEC)
	{
		printf("No\n");
		exit(0);
	}
	return 1;
}
void Swap(Point &a, Point &b)
{
	Point tmp=a;
	a=b;
	b=tmp;
}
map<pair<int,int> ,int> cnt;
map<pair<int,int> ,int>::iterator it;
pair<int,pair<int,int> > ord[20100000];
int main()
{
	srand(time(0));
	int n,i,j;
	scanf("%i",&n);n*=2;
	for(i=1;i<=n;i++) scanf("%lld %lld",&P[i].x,&P[i].y),cnt[mp(P[i].x,P[i].y)]=-1e9;
	int p1=1,p2=2;
	ll Best=-1;
	Point pt;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			pt=P[i]-P[j];
			ll sz=pt.sz();
			if(sz>Best) p1=i,p2=j,Best=sz;
		}
	}
	Swap(P[1],P[p1]);
	Swap(P[2],P[p2]);
	ll x,y;
	for(i=3;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			p[0]=P[1];p[1]=P[2];p[2]=P[i],p[3]=P[j];
			if(Find(x,y))
			{
				cnt[mp(x,y)]++;
			}
			p[0]=P[1];p[1]=P[i];p[2]=P[2];p[3]=P[j];
			if(Find(x,y))
			{
				cnt[mp(x,y)]++;
			}
			p[0]=P[1];p[1]=P[j];p[2]=P[2];p[3]=P[i];
			if(Find(x,y))
			{
				cnt[mp(x,y)]++;
			}
		}
	}
	int c=0;
	for(it=cnt.begin();it!=cnt.end();it++)
	{
		if(it->second>0)
		{
			//printf("Push: (%i, %i)\n",it->first.first,it->first.second);
			ord[++c]=mp(it->second,mp(it->first.first,it->first.second));
		}
	}
	sort(ord+1,ord+1+c);
	for(i=c;i>=c-2500 && i>0;i--)
	{
		//CheckTime();
		pt.x=ord[i].second.first;
		pt.y=ord[i].second.second;
		if(Check(pt,n))
		{
			printf("Yes\n");
			printf("%lld %lld\n",pt.x,pt.y);
			return 0;
		}
	}
	printf("No\n");
	/*while(CheckTime())
	{
		Chose(n);
		if(!Find(x,y)) continue;
		if(Check(Point(x,y),n))
		{
			printf("Yes\n");
			printf("%lld %lld\n",x,y);
			break;
		}
	}*/
	return 0;
}