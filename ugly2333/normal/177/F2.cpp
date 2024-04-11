//CF177F2
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111;
int n,m,t;
LL a[N];
int b[N];
pair<int,LL> c[N];
struct node{
	LL x;
	int s,p;
	node(LL X=0,int S=0,int P=0){
		x=X,s=S,p=P;
	}
	bool operator<(const node o)const{
		return s>o.s;
	}
}o;
priority_queue<node> q;
int main()
{
	int i,x,y,z;
	cin>>n>>m>>t;
	for(i=1;i<=m;i=i+1){
		cin>>x>>y>>z;
		x--,y--;
		y+=n;
		c[i]=make_pair(z,((LL)1<<x)|((LL)1<<y));
	}
	sort(c+1,c+m+1);
	for(i=1;i<=m;i=i+1)
		a[i]=c[i].second,b[i]=c[i].first;
	if(t==1){
		cout<<0;
		return 0;
	}
	t-=2;
	q.push(node(0,b[1],1));
	while(t--){
		o=q.top();
		q.pop();
		for(i=o.p+1;i<=m;i=i+1)
			if(!(a[i]&o.x))
				break;
		if(i<=m)
			q.push(node(o.x,o.s-b[o.p]+b[i],i));
		o.x|=a[o.p];
		for(i=o.p+1;i<=m;i=i+1)
			if(!(a[i]&o.x))
				break;
		if(i<=m)
			q.push(node(o.x,o.s+b[i],i));
	}
	cout<<q.top().s;
	return 0;
}