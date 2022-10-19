#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int h,q,c,rt,s[N<<5];
char buf[N];
unordered_map<int,int>mp;
inline int id(int x){if(mp.find(x)==mp.end())mp[x]=++c;return mp[x];}
inline int sum(int x){if(mp.find(x)==mp.end())return 0;return s[mp[x]];}
int main()
{
	scanf("%d%d",&h,&q);
	while(q--)
	{
		scanf("%s",buf);
		if(buf[0]=='a')
		{
			int x,v;
			scanf("%d%d",&x,&v);
			while(x)
			{
				s[id(x)]+=v;
				x>>=1;
			}
		}
		else
		{
			int k=1,sz=(1<<h),mx=0;
			long long ans=0;
			for(int i=1;i<=h;i++)
			{
				sz>>=1;
				int sl=sum(k<<1),sr=sum(k<<1|1),v=sum(k)-sl-sr;
				if(sl<sr)
				{
					ans+=1ll*sz*max(mx,sr+v);
					mx=max(mx,sl+v);
					k=(k<<1|1);
				}
				else
				{
					ans+=1ll*sz*max(mx,sl+v);
					mx=max(mx,sr+v);
					k=(k<<1);
				}
			}
			ans+=max(mx,sum(k));
			double r=1.0*ans/(1<<h);
			printf("%.6lf\n",r);
		}
	}
	return 0;
}