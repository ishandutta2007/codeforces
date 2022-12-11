#include<bits/stdc++.h>
using namespace std;
const int max_n=5e5+5;
struct Interval
{
	int l,r,id;
}I[max_n];
inline bool operator < (const Interval &a,const Interval &b)
{
	return a.l<b.l;
}
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			int b;
			scanf("%d",&b);
			I[i].l=i/(b+1)+1;
			I[i].r=b?i/b:n;
			I[i].id=i;
		}
		sort(I+1,I+n+1);
		typedef pair<int,int> P;
		priority_queue<P,vector<P>,greater<P> > Q;
		for(int i=1,j=1;i<=n;++i)
		{
			while(j<=n&&I[j].l==i)
			{
				Q.push(P(I[j].r,I[j].id));
				++j;
			}
			assert(!Q.empty());
			assert(Q.top().first>=i);
			a[Q.top().second]=i;
			Q.pop();
		}
		for(int i=1;i<=n;++i)
			printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}