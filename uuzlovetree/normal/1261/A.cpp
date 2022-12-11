#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define maxn 2005
using namespace std;
int T,n,k; 
char s[maxn];
vector<pii> Ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		Ans.clear();
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='(')
			{
				int j=i+1;
				bool yes=0;
				for(;j<=n;++j)if(s[j]==')'){yes=1;break;}
				if(yes)
				{
					Ans.push_back(mp(i+1,j));
					reverse(s+i+1,s+j+1);
				}
				i++;
			}
			else
			{
				int j=i+1;
				bool yes=0;
				for(;j<=n;++j)if(s[j]=='('){yes=1;break;}
				if(yes)
				{
					Ans.push_back(mp(i,j));
					reverse(s+i,s+j+1);
				}
				i++;
			}
		}
		int cnt=n/2;
		for(int i=1;i<=n;++i)if(s[i]==')')
		{
			if(cnt==k)break;
			for(int j=i+1;j<=n;++j)if(s[j]=='(')
			{
				Ans.push_back(mp(i,j));
				reverse(s+i,s+j+1);
				cnt--;
				break;
			}
		}
		printf("%d\n",Ans.size());
		for(auto x:Ans)printf("%d %d\n",x.first,x.second);
	}
}