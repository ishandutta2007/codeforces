#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],l,r,b[N];
vector<int>p[N];
long long s;
void add(int x,int v)
{
	for(int i=x;i<=n;i+=i&(-i))
		b[i]+=v;
}
int ask(int x)
{
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v+=b[i];
	return v;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),p[a[i]].push_back(i);
	l=1,r=n;
	for(int i=n;i;i--)
	{
		if(p[i].size())
		{
			int vl=min(p[i][0],r+1),vr=max(p[i].back(),l-1);
			l=vl,r=vr;
			for(auto j:p[i])
				add(j,1);
			s+=ask(r)-ask(l-1);
		}
	}
	printf("%lld\n",s);
	return 0;
}