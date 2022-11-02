#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long

bool tmp[33000];
int T[10][5005], P[5005], wynik=0;
int tab[5005];
int pop[10], A[10];
vector<pair<int, int> > Pi, V;
int n, m;

int gc(int a, int b)
{
	while(a!=0)
	{
		if(a<b) swap(a, b);
		a=a%b;
	}
	return b;
}

void sito()
{
	int j=0;
	for(int i=2; i<33000; i++)
	{
		while(i>P[j]) j++;
		if(!tmp[i])
		{
			int qwe;
			if(P[j]==i) qwe=-1;
			else qwe=1;
			Pi.PB(MP(i, qwe));
			int x=i;
			while(x<33000)
			{
				tmp[x]=1;
				x+=i;
			}
		}
	}
}

void wyn(int x)
{
	for(int i=0; Pi[i].F*Pi[i].F<=x; i++)
	{
		if(x==1) break;
		while(x%Pi[i].F==0)
		{
			wynik+=Pi[i].S;
			x/=Pi[i].F;
		}
	}
	if(x!=1)
	{
		int p=0, k=m-1, mid=(p+k)/2;
		bool b=0;
		while(p<=k)
		{
			if(P[mid]<x) p=mid+1;
			if(P[mid]>x) k=mid-1;
			if(P[mid]==x) {b=1; break;}
			mid=(p+k)/2;
		}
		if(b) wynik--;
		else wynik++;
	}
}

void add(int x, int ind)
{
	for(int i=0; i<V.size(); i++)
	{
		while(x%V[i].F==0)
		{
			T[i][ind]++;
			x/=V[i].F;
		}
	}
}

int main()
{
	//printf("%d\n", gc(4,20));
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) scanf("%d", tab+i);
	for(int i=0; i<m; i++) scanf("%d", P+i);
	sito();
	int gcd=tab[0];
	for(int i=0; Pi[i].F*Pi[i].F<=tab[0]; i++)
	{
		if(tab[0]==1) break;
		if(tab[0]%Pi[i].F==0)
		{
			V.PB(Pi[i]);
			while(tab[0]%Pi[i].F==0)
			{
				T[V.size()-1][0]++;
				tab[0]/=Pi[i].F;
			}
		}
	}
	if(tab[0]!=1)
	{
		bool b=0;
		for(int i=0; i<m; i++) if(P[i]==tab[0]) b=1;
		if(b) V.PB(MP(tab[0], -1));
		else V.PB(MP(tab[0], 1));
		T[V.size()-1][0]=1;
	}
	for(int i=1; i<n; i++)
	{
		gcd=gc(gcd, tab[i]);
		wyn(tab[i]/gcd);
		//printf("%d\n", wynik);
		add(gcd, i);
	}
	//for(int i=0; i<V.size(); i++) printf("kurwa %d %d\n", V[i].F, T[i][3]);
	for(int i=n-1; i>=0; i--)
	{
		int wyn=0;
		for(int j=0; j<V.size(); j++)
		{
			A[j]=T[j][i]-pop[j];
			wyn+=A[j]*V[j].S;
		}
		if(wyn<0) for(int j=0; j<V.size(); j++) pop[j]=T[j][i];
		else wynik+=wyn;
		//printf("%d, %d\n", i, wyn);
	}
	printf("%d\n", wynik);
	return 0;
}