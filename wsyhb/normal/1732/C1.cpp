#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],sum[max_n][30],nxt[max_n][30],lst[max_n][30];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;++i)
		{
			int x;
			scanf("%d",&x);
			a[i]=x;
			for(int j=0;j<30;++j)
			{
				int v=x>>j&1;
				if(v)
				{
					sum[i][j]=sum[i-1][j]+1;
					lst[i][j]=i;
				}
				else
				{
					sum[i][j]=sum[i-1][j];
					lst[i][j]=lst[i-1][j];
				}
			}
		}
		for(int j=0;j<30;++j)
			nxt[n+1][j]=n+1;
		for(int i=n;i>=1;--i)
			for(int j=0;j<30;++j)
			{
				if(a[i]>>j&1)
					nxt[i][j]=i;
				else
					nxt[i][j]=nxt[i+1][j];
			}
		while(q--)
		{
			int L,R;
			scanf("%d%d",&L,&R);
			typedef pair<int,int> P;
			vector<P> res;
			int l=R,r=L;
			for(int i=0;i<30;++i)
			{
				int v=sum[R][i]-sum[L-1][i];
				if(v&1)
				{
					if(v>1)
					{
						int a=nxt[nxt[L][i]+1][i];
						int b=lst[lst[R][i]-1][i];
						l=min(l,a),r=max(r,b);
						res.push_back(P(nxt[L][i],lst[R][i]));
					}
				}
				else if(v)
				{
					l=min(l,nxt[L][i]);
					r=max(r,lst[R][i]);
				}
			}
			if(res.empty())
			{
				if(l>r)
					l=r=L;
				printf("%d %d\n",l,r);
				continue;
			}
			sort(res.begin(),res.end(),greater<P>());
			multiset<int> S;
			for(P v:res)
				S.insert(v.second);
			int ans_l=-1,ans_r=-1,ans_len=1e9;
			for(P v:res)
			{
				int r_now=max(r,*S.rbegin());
				if(l>r_now)
				{
					ans_l=ans_r=L,ans_len=1e9;
					break;
				}
				if(r_now-l+1<ans_len)
				{
					ans_l=l,ans_r=r_now;
					ans_len=r_now-l+1;
				}
				l=min(l,v.first);
				S.erase(S.find(v.second));
			}
			if(ans_len!=1e9)
			{
				if(l>r)
					ans_l=ans_r=L;
				else if(r-l+1<ans_len)
					ans_l=l,ans_r=r;
			}
			printf("%d %d\n",ans_l,ans_r);
		}
	}
	return 0;
}