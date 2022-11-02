#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define MP make_pair
#define PB push_back
#define S second
#define F first
#define LL long long
#define D double

vector<pair<int, int> > V[2];
int p[2]={0, 0};
priority_queue<pair<int, int> > Q[2];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.F==b.F) return a.S>b.S;
	return a.F<b.F;
}

int main()
{
	int n, x;
	scanf("%d%d", &n, &x);
	for(int i=0; i<n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		V[a].PB(MP(b, c));
	}
	sort(V[0].begin(), V[0].end(), cmp);
	sort(V[1].begin(), V[1].end(), cmp);
	bool b=0;
	int res=0, res2=0, h=x;
	while(p[b]<V[b].size() && V[b][p[b]].F<=h) {Q[b].push(MP(V[b][p[b]].S, V[b][p[b]].F)); p[b]++;}
	while(!Q[b].empty())
	{
		res++;
		h+=Q[b].top().F;
		Q[b].pop();
		b=1-b;
		while(p[b]<V[b].size() && V[b][p[b]].F<=h) {Q[b].push(MP(V[b][p[b]].S, V[b][p[b]].F)); p[b]++;}
	}
	h=x;
	b=1;
	p[0]=0;
	p[1]=0;
	while(!Q[0].empty()) Q[0].pop();
	while(!Q[1].empty()) Q[1].pop(); 
	while(p[b]<V[b].size() && V[b][p[b]].F<=h) {Q[b].push(MP(V[b][p[b]].S, V[b][p[b]].F)); p[b]++;}
	while(!Q[b].empty())
	{
		res2++;
		h+=Q[b].top().F;
		Q[b].pop();
		b=1-b;
		while(p[b]<V[b].size() && V[b][p[b]].F<=h) {Q[b].push(MP(V[b][p[b]].S, V[b][p[b]].F)); p[b]++;}
	}
	printf("%d\n", max(res, res2));
	return 0;
}