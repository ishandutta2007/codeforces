#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
const int inf=1e9+7;
int n,s,x;
pair<int,int> Ask(int i)
{
	if(i==-1) return mp(inf,-1);
	printf("? %i\n",i);
	fflush(stdout);
	pair<int,int> p;
	scanf("%i %i",&p.first,&p.second);
	return p;
}
void Ans(int i)
{
	if(i==inf) printf("! -1\n");
	else printf("! %i\n",i);
	fflush(stdout);
	exit(0);
}
int main()
{
	srand(time(0));
	scanf("%i %i %i",&n,&s,&x);
	int mx=0,fir=s;
	for(int t=1000;t--;)
	{
		int i=(rand()*rand()^rand())%n+1;
		pair<int,int> tmp=Ask(i);
		if(tmp.first<x)
		{
			if(mx<tmp.first) mx=tmp.first,fir=i;
		}
		if(tmp.first==x) Ans(x);
	}
	int val=0;
	do
	{
		pair<int,int> tmp=Ask(fir);
		val=tmp.first;
		fir=tmp.second;
	}while(val<x);
	Ans(val);
	return 0;
}