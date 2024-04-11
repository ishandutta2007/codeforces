#include<bits/stdc++.h>
using namespace std;
const int N=100111;
struct zh
{
	int a,b,id;
	zh(){}
	zh(int _a,int _b,int _id):a(_a),b(_b),id(_id){}
	bool operator<(const zh k)const
	{
		return b<k.b||(b==k.b&&a>k.a);
	}
}c[N];
int main()
{
	int n,p,k;
	scanf("%d%d%d",&n,&p,&k);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		c[i]=zh(a,b,i+1);	
	} 
	sort(c,c+n);
	priority_queue<pair<pair<int,int>,int>>q;
	for(int i=p-k;i<n;i++)
		q.push(make_pair(make_pair(c[i].a,i),c[i].id));
	int mn=n;
	for(int i=0;i<k;i++)
	{
		pair<pair<int,int>,int> w=q.top();
		q.pop();
		printf("%d ",w.second);
		mn=min(mn,w.first.second);
	}
	int t=p-k;
	while(t--)
		printf("%d ",c[--mn].id);
	puts("");
	return 0;
}