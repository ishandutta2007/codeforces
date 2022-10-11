#include <cstdio>
#include <queue>
#include <utility>
#include <map>

int v[20];
int n,m;

typedef std::pair<int,int> ii;
typedef std::pair<ii,int> iii;//start,end,on

inline int lsb(int mask)
{
  return 31-__builtin_clz(mask&-mask);
}

long long int dp[20][1100000];
bool visit[20][1100000];

long long int fw_track()
{
	std::queue<ii> q;
	for(int i=0;i<n;i++)
	{
		ii c=ii(i,1<<i);
		q.push(c);
		dp[i][1<<i]=1;
		visit[i][1<<i]=true;
	}
	long long int ans=0;
	int cur_it=1;
	long long int cur_ans=0;
	while(!q.empty())
	{
		
		int end=q.front().first;
		int on=q.front().second;
		int now=on&-on;
		int start=lsb(now);

		int it=0;
		for(int i=on;i!=0;i&=~(i&-i)) it++;
		long long int paths=dp[end][on];

		int e=v[end];
		

		if(cur_it<it)
		{
			ans+=((cur_ans)/2)/cur_it;
			cur_ans=0;
			cur_it=it;
		}
		while(e)
		{
			int next=e&(-e);
			e&=~next;
			if(next==now)
			{
				if(it>2)
					cur_ans+=paths;
			}
			else if(!(next & on))
			{
				ii going=ii(next>now?lsb(next):start,on|next);
				if(!visit[going.first][going.second])
				{
					visit[going.first][going.second]=true;
					q.push(going);
				}
				dp[going.first][going.second]+=paths;
			}
		}
		q.pop();
	}
	if(cur_it>1)
	{
		ans+=((cur_ans)/2)/cur_it;
	}
	return ans;
}


int main()
{
	
	scanf("%i %i",&n,&m);
	for(int i=0;i<m;i++)
	{
		int t1,t2;scanf("%i %i",&t1,&t2);t1--;t2--;
		v[t1]|=1<<t2;
		v[t2]|=1<<t1;
	}
	printf("%lli\n",fw_track());
	return 0;
}