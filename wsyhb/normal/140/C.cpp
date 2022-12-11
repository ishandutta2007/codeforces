#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int r[max_n],Hash[max_n],cnt[max_n];
struct Snowmen
{
	int a,b,c;
	inline Snowmen(int p,int q,int r)
	{
		if(p<q)
			swap(p,q);
		if(p<r)
			swap(p,r);
		if(q<r)
			swap(q,r);
		a=p,b=q,c=r;
	}
};
vector<Snowmen> ans;
typedef pair<int,int> P;
priority_queue<P> q;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",r+i);
		Hash[i]=r[i];
	}
	sort(Hash+1,Hash+n+1);
	int R=unique(Hash+1,Hash+n+1)-Hash-1;
	for(int i=1;i<=n;++i)
	{
		r[i]=lower_bound(Hash+1,Hash+R+1,r[i])-Hash;
		++cnt[r[i]];
	}
	for(int i=1;i<=R;++i)
		q.push(P(cnt[i],i));
	while((int)q.size()>=3)
	{
		P x=q.top();
		q.pop();
		P y=q.top();
		q.pop();
		P z=q.top();
		q.pop();
		ans.push_back(Snowmen(Hash[x.second],Hash[y.second],Hash[z.second]));
		if(--x.first)
			q.push(x);
		if(--y.first)	
			q.push(y);
		if(--z.first)
			q.push(z);
	}
	printf("%d\n",(int)ans.size());
	for(vector<Snowmen>::iterator it=ans.begin();it!=ans.end();++it)
		printf("%d %d %d\n",it->a,it->b,it->c);
	return 0;
}