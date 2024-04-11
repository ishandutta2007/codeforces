#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],e=1;
bool vis_node[max_n],vis_edge[max_n<<1];
inline void add_edge(int x,int y)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e;
	End[++e]=x,Next[e]=Last[y],Last[y]=e;
}
int a[2][max_n],cnt[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			Last[i]=cnt[i]=0;
			vis_node[i]=false;
		}
		e=1;
		for(int i=2;i<=(n<<1|1);++i)
			vis_edge[i]=false;
		for(int i=0;i<=1;++i)
			for(int j=1;j<=n;++j)
			{
				scanf("%d",&a[i][j]);
				++cnt[a[i][j]];
			}
		bool flag_exist=true;
		for(int i=1;i<=n;++i)
		{
			if(cnt[i]!=2)
			{
				flag_exist=false;
				break;
			}
		}
		if(!flag_exist)
		{
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;++i)
			add_edge(a[0][i],a[1][i]);
		vector<int> pos;
		for(int i=1;i<=n;++i)
		{
			if(vis_node[i])
				continue;
			int x=i;
			vector<int> edge;
			int cnt_odd=0;
			do
			{
				vis_node[x]=true;
				bool flag=false;
				for(int j=Last[x];j;j=Next[j])
				{
					if(!vis_edge[j])
					{
						edge.push_back(j);
						cnt_odd+=j&1;
						vis_edge[j]=vis_edge[j^1]=true;
						x=End[j];
						flag=true;
						break;
					}			
				}
				assert(flag);
			}while(x!=i);
			if(cnt_odd>(int)edge.size()-cnt_odd)
			{
				for(vector<int>::iterator it=edge.begin();it!=edge.end();++it)
					*it=*it^1;
				cnt_odd=(int)edge.size()-cnt_odd;
			}
			for(vector<int>::iterator it=edge.begin();it!=edge.end();++it)
			{
				if(*it&1)
					pos.push_back(*it>>1);
			}
		}
		printf("%d\n",(int)pos.size());
		for(int i=0;i<int(pos.size());++i)
			printf("%d%c",pos[i],i+1<int(pos.size())?' ':'\n');
		if(pos.empty())
			putchar('\n');
	}
	return 0;
}