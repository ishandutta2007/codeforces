#include<cstdio>
#include<set>
#include<algorithm>

using namespace std;

int atks[110],defs[110];
int ciel[110];
int aid=0,did=0;
int N,M;

int tmp[110];

int solve_all()
{
	if(N>M) return 0;
	multiset<int> se;
	for(int i=0;i<M;i++) se.insert(ciel[i]);
	for(int i=0;i<did;i++)
	{
		multiset<int>::iterator it=se.upper_bound(defs[i]);
		if(it==se.end()) return 0;
		se.erase(it);
	}
	int id=0;
	multiset<int>::iterator it=se.begin();
	for(;it!=se.end();it++)
	{
		tmp[id]=*it;
		id++;
	}
	int res=0;
	int f_id=id;
	for(int i=id-1,j=aid-1;i>=0&&j>=0;i--,j--)
	{
		int cs=tmp[i],js=atks[j];
		if(cs<js) return 0;
		res+=(cs-js);
		f_id=i;
	}
	for(int i=f_id-1;i>=0;i--)
	{
		res+=tmp[i];
	}
	return res;
}

int solve_notall()
{
	int res=0;
	for(int k=0;k<=min(aid,M);k++)
	{
		int tmp=0;
		for(int i=0;i<k;i++)
		{
			int a=i,b=M-k+i;
			if(atks[a]>ciel[b]) continue;
			tmp+=ciel[b]-atks[a];
		}
		res=max(res,tmp);
	}
	return res;
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		char ch[4];
		int num;
		scanf("%s%d",ch,&num);
		if(ch[0]=='A')
		{
			atks[aid]=num;
			aid++;
		}
		else
		{
			defs[did]=num;
			did++;
		}
	}
	for(int i=0;i<M;i++)
	{
		scanf("%d",ciel+i);
	}
	sort(atks,atks+aid);
	sort(defs,defs+did);
	sort(ciel,ciel+M);
	int ans=0;
	ans=max(ans,solve_all());
	ans=max(ans,solve_notall());
	printf("%d\n",ans);
	return 0;
}