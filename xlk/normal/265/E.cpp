#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
typedef pair<int,int>ii;
typedef pair<ll,ll>LL;
LL u,v;
int d[100020];
int c[100020];
int n,q;
ll f[100020],a,b;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",d+i);
	for(int i=1;i<=n;i++)
		scanf("%d",c+i);
	for(int i=0;i<q;i++)
	{
		cin>>a>>b;
		memset(f,0xc0,sizeof f);
		u=ii(0,0);
		v=ii(-0x3f3f3f3f3f3f3f3fLL,0);
		for(int i=1;i<=n;i++)
		{
			ll w=-0x3f3f3f3f3f3f3f3fLL;
			if(c[i]!=u.Y)
				w=max(w,u.X+b*d[i]);
			else
				w=max(w,v.X+b*d[i]);
			w=max(w,f[c[i]]+a*d[i]);
			f[c[i]]=max(f[c[i]],w);
			if(w>v.X)
			{
				if(w>u.X)
				{
					if(c[i]!=u.Y)
						v=u;
					u=LL(w,c[i]);
				}
				else if(c[i]!=u.Y)
				{
					v=LL(w,c[i]);
				}
			}
		}
		cout << u.X << endl;
	}
	return 0;
}