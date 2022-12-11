#include<bits/stdc++.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const int N=5e5+5;
int m[N];
ll l[N],r[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",m+i);
	deque<P> q;
	for(int i=1;i<=n;i++)
	{
		while(q.size()&&q.back().second>m[i]) q.pop_back();
		if(q.empty()) l[i]=1ll*i*m[i];
		else l[i]=l[q.back().first]+1ll*(i-q.back().first)*m[i];
		q.push_back(P(i,m[i])); 
	}
	q.clear();
	for(int i=n;i>=1;i--)
	{
		while(q.size()&&q.back().second>m[i]) q.pop_back();
		if(q.empty()) r[i]=1ll*(n-i+1)*m[i];
		else r[i]=r[q.back().first]+1ll*(q.back().first-i)*m[i];
		q.push_back(P(i,m[i]));
	}
	ll ans=0;
	int id;
	for(int i=1;i<=n;i++)
		if(l[i]+r[i]-m[i]>ans)
		{
			ans=l[i]+r[i]-m[i];
			id=i;
		}
	for(int i=id-1;i>=1;i--) m[i]=min(m[i],m[i+1]);
	for(int i=id+1;i<=n;i++) m[i]=min(m[i],m[i-1]);
	for(int i=1;i<=n;i++) printf("%d%c",m[i],i<n?' ':'\n');
	return 0;
}