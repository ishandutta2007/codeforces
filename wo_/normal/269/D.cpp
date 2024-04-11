#include<cstdio>
#include<utility>
#include<set>
#include<vector>
#include<cassert>
#include<algorithm>

using namespace std;

const int inf=1000000009;

typedef pair<int,int> P;
typedef pair<P,int> PP;

set<PP> se;

struct segm{
	int l,r;
	int height;
	int id;
	segm(){}
	segm(int a,int b,int c,int d):l(a),r(b),height(c),id(d){}
};

bool cmp(const segm &s1,const segm &s2)
{
	return s1.height<s2.height;
}

segm segs[100100];

int ls[100100],rs[100100];

int dp[100100];

int main()
{
	int N,t;
	scanf("%d%d",&N,&t);
	segs[0]=segm(-inf,inf,0,0);
	ls[0]=-inf,rs[0]=inf;
	for(int i=1;i<=N;i++)
	{
		int h,l,r;
		scanf("%d%d%d",&h,&l,&r);
		segs[i]=segm(l,r,h,i);
		ls[i]=l,rs[i]=r;
	}
	segs[N+1]=segm(-inf+1,inf-1,t,N+1);
	ls[N+1]=-inf+1,rs[N+1]=inf-1;
	sort(segs,segs+N+2,cmp);
	dp[0]=inf*2;
	se.insert(PP(P(-inf,inf),0));
	for(int i=1;i<=N+1;i++)
	{
		int id=segs[i].id;
		set<PP>::iterator it=se.upper_bound(PP(P(ls[id],rs[id]),id));
		int le=ls[id],ri=rs[id];
		it--;
		vector<PP> topush;
		for(;;)
		{
			if(it==se.end())
			{
				break;
			}
			if((*it).first.first>=ri) break;
			PP pp=*it;
			se.erase(it++);
			int a=pp.first.first,b=pp.first.second,c=pp.second;
			int aa=max(ls[c],le),bb=min(rs[c],ri);
			int a2=max(a,le),b2=min(b,ri);
			if((a<=aa&&bb<=b)) dp[id]=max(dp[id],min(b2-a2,dp[c]));
			if(a<a2) topush.push_back(PP(P(a,a2),c));
			if(b2<b) topush.push_back(PP(P(b2,b),c));
		}
		for(int j=0;j<topush.size();j++)
		{
			se.insert(topush[j]);
		}
		se.insert(PP(P(le,ri),id));
	}
	printf("%d\n",dp[N+1]);
	return 0;
}