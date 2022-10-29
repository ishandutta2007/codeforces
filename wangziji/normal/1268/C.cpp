#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
#define int long long
using namespace std;
inline int lowbit(int x)
{
	return x&(-x);
}
int tree[500005],n,a[500005],pos[500005];
inline void add(int x,int y)
{
	if(x>n)
		return ;
	tree[x]+=y;
	add(x+lowbit(x),y);
}
inline int ask(int x)
{
	if(x==0)
		return x;
	return tree[x]+ask(x-lowbit(x));
}
set <int> s;
signed main(int argc, char** argv) {
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		pos[a[i]]=i; 
	}
	int ans=0,l=0,r=0,now=pos[1];
	s.insert(-10),s.insert(1e9);
	for(int i=1;i<=n;i++)
	{
		//cout << "***" << now << "***" << endl; 
		ans+=i-1-ask(pos[i]);
		ans+=abs(now-pos[i]); 
		add(pos[i],1);
		if(pos[i]<now) ++l;
		if(pos[i]>now) ++r;
		s.insert(pos[i]);
		set<int>::iterator it=s.lower_bound(now);
		--it;
		int lst=*it;
		int nxt=*s.upper_bound(now);
		//cout << l << " " << r << endl;
		//cout << lst << " " << now << " " << nxt << endl;
		if(l-r>1)
		{
			ans-=now-lst;
			now=lst;
			--l,++r;
		}
		else if(r-l>1)
		{
			ans-=nxt-now;
			now=nxt;
			++l,--r;
		}
		//cout << -(i/2)*(i/2+1)/2-((i-1)/2)*((i-1)/2+1)/2 << endl;
		printf("%lld ",ans-(i/2)*(i/2+1)/2-((i-1)/2)*((i-1)/2+1)/2);
	}
	return 0;
}