#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,nxt[100005];
char s[100005];
vector<pair<int,int> >LL,LR,RL,RR;
void solve(pair<int,int>x)
{
	int st=x.first;
	while(st)
	{
		printf("%d ",st);
		st=nxt[st];
	}
}
int main()
{
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='L')
		{
			if(!LR.empty())
			{
				pair<int,int>x=LR.back();
				LR.pop_back();
				nxt[x.second]=i;
				LL.push_back(make_pair(x.first,i));
			}
			else if(!RR.empty())
			{
				pair<int,int>x=RR.back();
				RR.pop_back();
				nxt[x.second]=i;
				RL.push_back(make_pair(x.first,i));
			}
			else LL.push_back(make_pair(i,i));
		}
		else
		{
			if(!RL.empty())
			{
				pair<int,int>x=RL.back();
				RL.pop_back();
				nxt[x.second]=i;
				RR.push_back(make_pair(x.first,i));
			}
			else if(!LL.empty())
			{
				pair<int,int>x=LL.back();
				LL.pop_back();
				nxt[x.second]=i;
				LR.push_back(make_pair(x.first,i));
			}
			else RR.push_back(make_pair(i,i));
		}
	}
	printf("%d\n",(int)(LR.size()+LL.size()+RL.size()+RR.size()-1));
	int st=0;
	if(LL.size()>RR.size()||(LL.size()==RR.size()&&LR.size()>RL.size()))st=0;
	else st=1;
	while(1)
	{
		bool flag=0;
		if(st==0)
		{
			while(!LR.empty())
			{
				flag=1;
				solve(LR.back());
				LR.pop_back();
			}
			if(!LL.empty())
			{
				flag=1;
				solve(LL.back());
				LL.pop_back();
				st=1;
			}
		}
		else
		{
			while(!RL.empty())
			{
				flag=1;
				solve(RL.back());
				RL.pop_back();
			}
			if(!RR.empty())
			{
				flag=1;
				solve(RR.back());
				RR.pop_back();
				st=0;
			}
		}
		if(flag==0)break;
	}
	return 0;
}