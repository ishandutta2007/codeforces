#include <bits/stdc++.h>
#define Maxn 1000007
#define inf 2000000007
using namespace std;
int n,m;
char p[Maxn],q[Maxn],s[Maxn];
pair<int,int> f[Maxn],pf[Maxn];
struct seg
{
	int a,k,len;
};
vector<seg> G,x,y;
void dp()
{
	for (int i=1;i<=n;i++)
		f[i]=make_pair(inf,0);
	f[0]=make_pair(0,0);
	for (int i=1;i<=n;i++)
	{
		x.clear(),y.clear();
//extend the palindrome set
		for (int j=0;j<(int)G.size();j++)
			if (G[j].a>1&&s[G[j].a-1]==s[i]) x.push_back((seg){G[j].a-1,G[j].k,G[j].len});
		int r=-n;
//build the sequence
		for (int j=0;j<(int)x.size();j++)
		{
			if (x[j].a-x[j].k==r) y.push_back(x[j]);
			else
			{				
				y.push_back((seg){x[j].a,x[j].a-r,1});
				if (x[j].len>1) y.push_back((seg){x[j].a+x[j].k,x[j].k,x[j].len-1});
			}
			r=x[j].a+x[j].k*(x[j].len-1);
		}
		if (i>1&&s[i-1]==s[i]) 
		{
			y.push_back((seg){i-1,i-r-1,1});
			r=i-1;
		}
		y.push_back((seg){i,i-r,1});
//extend the sequence
		G.clear();
		seg t=y[0];
		for (int j=1;j<(int)y.size();j++)
			if (t.k==y[j].k) t.len+=y[j].len;
			else
			{
				G.push_back(t);
				t=y[j];
			}
		G.push_back(t);
//dynamic programming
		if (s[i]==s[i-1]) f[i]=make_pair(f[i-2].first,i-2);
		for (int j=0;j<(int)G.size();j++)
		{
			int rx=G[j].a+G[j].k*(G[j].len-1);
			pair<int,int> now=make_pair(f[rx-1].first+1,rx-1);
			if (G[j].len>1) now=min(now,pf[G[j].a-G[j].k]);
			if (G[j].a>=G[j].k) pf[G[j].a-G[j].k]=now;
			if (i%2==0) f[i]=min(f[i],now);
		}
	}
}
int main()
{
	scanf("%s",p+1);
	scanf("%s",q+1);
	m=strlen(p+1);
	for (int i=1;i<=2*m;i++)
		if (i%2==1) s[i]=p[i/2+1]; else s[i]=q[i/2];
	n=2*m;
	dp();
	if (f[n].first>m) printf("%d\n",-1);
	else
	{
		printf("%d\n",f[n].first);
		int now=n;
		while (now>0)
		{
			int pos=f[now].second;
			if (pos<now-2) printf("%d %d\n",pos/2+1,now/2);
			now=pos;
		}
	}
	return 0;
}