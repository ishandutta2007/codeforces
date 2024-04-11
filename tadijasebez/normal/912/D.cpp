#include <stdio.h>
#include <queue>
#include <map>
using namespace std;
#define ll long long
#define mp make_pair
priority_queue<pair<ll,pair<int,int> > > pq;
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
map<pair<int,int> ,bool> was;
int n,m,r;
void Push(int x, int y)
{
	if(x<=0 || x>n || y<=0 || y>m || was[mp(x,y)]) return;
	was[mp(x,y)]=1;
	ll sol=(ll)(min(x+r,n+1)-max(r,x))*(min(y+r,m+1)-max(r,y));
	pq.push(mp(sol,mp(x,y)));
}
ll ans;
int main()
{
	int k,i;
	scanf("%i %i %i %i",&n,&m,&r,&k);
	for(i=1;i<=n;i++) Push(i,m/2+1);
	while(k--)
	{
		ans+=pq.top().first;
		int x=pq.top().second.first;
		int y=pq.top().second.second;
		pq.pop();
		Push(x,y+1);
		Push(x,y-1);
		Push(x+1,y);
		Push(x-1,y);
	}
	printf("%.10llf\n",(double)ans/(n-r+1)/(m-r+1));
	return 0;
}