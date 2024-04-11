#include<bits/stdc++.h>
using namespace std;
inline int Sqrt(long long x)
{
	int s=sqrt(x);
	while(1ll*s*s>x)
		--s;
	while((s+1ll)*(s+1)<=x)
		++s;
	return s;
}
typedef pair<long long,long long> P;
vector<P> Seg;
long long ans;
inline void update()
{
	long long delta=0;
	for(int i=0;i<int(Seg.size());++i)
	{
		int S=Sqrt(Seg[i].first+delta);
		if(Seg[i].second+delta>1ll*S*S+S)
		{
			int nxt=max(Seg[i].second-Seg[i].first,S+1ll);
			delta=max(delta,1ll*nxt*nxt-Seg[i].first);
		}
	}
	if(delta==0)
	{
		printf("%lld\n",ans);
		exit(0);
	}
	ans+=delta;
	for(int i=0;i<int(Seg.size());++i)
		Seg[i].first+=delta,Seg[i].second+=delta;
	vector<P> Seg_new;
	for(int i=0;i<int(Seg.size());++i)
	{
		int S=Sqrt(Seg[i].first);
		long long lim=1ll*S*S+S;
		int j=i;
		while(j+1<int(Seg.size())&&Seg[j+1].second<=lim)
			++j;
		Seg_new.push_back(P(Seg[i].first,Seg[j].second));
		i=j;
	}
	Seg.swap(Seg_new);
}
int main()
{
	int n;
	scanf("%d",&n);
	Seg.resize(n);
	for(int i=0;i<n;++i)
	{
		int a;
		scanf("%d",&a);
		Seg[i]=P(a,a);
	}
	while(1)
		update();
	return 0;
}