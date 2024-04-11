#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
char s[max_n<<1];
int pref[max_n<<1];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s",&n,s+1);
		int mn=0;
		for(int i=1;i<=2*n;++i)
		{
			pref[i]=pref[i-1]+(s[i]=='('?1:-1);
			mn=min(mn,pref[i]);
		}
		if(!mn)
		{
			puts("0");
			continue;
		}
		int L=-1,R=-1;
		for(int i=0;i<=2*n;++i)
		{
			if(pref[i]<0)
			{
				L=i;
				break;
			}
		}
		for(int i=2*n;i>=0;--i)
		{
			if(pref[i]<0)
			{
				R=i;
				break;
			}
		}
		assert(L!=-1&&R!=-1);
		int l=0,r=2*n;
		for(int i=0;i<=L;++i)
		{
			if(pref[i]>pref[l])
				l=i;
		}
		for(int i=2*n;i>=R;--i)
		{
			if(pref[i]>pref[r])
				r=i;
		}
		assert(l<r);
		bool flag=true;
		for(int i=l;i<=r;++i)
		{
			if(pref[l]+pref[r]<pref[i])
			{
				flag=false;
				break;
			}
		}
		if(flag)
			printf("1\n%d %d\n",l+1,r);
		else
		{
			int pos=0;
			for(int i=1;i<=2*n;++i)
			{
				if(pref[i]>pref[pos])
					pos=i;
			}
			assert(pos>=1&&pos<2*n);
			printf("2\n%d %d\n%d %d\n",1,pos,pos+1,2*n);
		}
	}
	return 0;
}