#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

vector<int> luckys;
bool islucky[10100];

int dat[100100];
int sum[500]={};//uniformly added
int B;

int cnt[500][10100]={};//[i][j]=bucket i has x j's

void gen(int c)
{
	if(c!=0) luckys.push_back(c);
	if(c*10+4<10100) gen(c*10+4);
	if(c*10+7<10100) gen(c*10+7);
}

void add(int l,int r,int x)
{
	//add x to [l,r)
	int i=l;
	while(i<r)
	{
		if(i%B==0&&i+B<=r)
		{
			sum[i/B]+=x;
			i+=B;
		}
		else
		{
			int id=i/B;
			cnt[id][dat[i]]--;
			dat[i]+=x;
			cnt[id][dat[i]]++;
			i++;
		}
	}
}

int luckycount(int l,int r)
{
	int i=l;
	int res=0;
	while(i<r)
	{
		if(i%B==0&&i+B<=r)
		{
			for(int j=0;j<luckys.size();j++)
			{
				if(luckys[j]<sum[i/B]) continue;
				res+=cnt[i/B][luckys[j]-sum[i/B]];
			}
			i+=B;
		}
		else
		{
			//for(int j=0;j<luckys.size();j++)
			//{
			//	if(dat[i]+sum[i/B]==luckys[j])
			//	{
			//		res++;
			//	}
			//}
			if(islucky[dat[i]+sum[i/B]]) res++;
			i++;
		}
	}
	return res;
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	B=(int)sqrt(N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",dat+i);
		cnt[i/B][dat[i]]++;
	}
	gen(0);
	for(int i=0;i<10100;i++) islucky[i]=false;
	for(int i=0;i<luckys.size();i++)
	{
		islucky[luckys[i]]=true;
	}
	for(int i=0;i<M;i++)
	{
		char ch[10];
		int l,r,x;
		scanf("%s",ch);
		if(ch[0]=='c')
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",luckycount(l-1,r));
		}
		else
		{
			scanf("%d%d%d",&l,&r,&x);
			add(l-1,r,x);
		}
	}
	return 0;
}