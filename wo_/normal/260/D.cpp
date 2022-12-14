#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct node{
	int id;
	int color;
	int val;
	node(){}
	node(int a,int b,int c):id(a),color(b),val(c){}
};

vector<node> black,white;

struct edge{
	int u,v;
	int val;
	edge(){}
	edge(int a,int b,int c):u(a),v(b),val(c){}
};

vector<edge> ans;

bool cmp(const node &n1,const node &n2)
{
	return n1.val>n2.val;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int c,s;
		scanf("%d%d",&c,&s);
		if(c==0) white.push_back(node(i+1,c,s));
		else black.push_back(node(i+1,c,s));
	}
	sort(white.begin(),white.end(),cmp);
	sort(black.begin(),black.end(),cmp);
	int w=0,b=0;
	while(w<white.size()&&b<black.size())
	{
		int cost=min(white[w].val,black[b].val);
		ans.push_back(edge(white[w].id,black[b].id,cost));
		white[w].val-=cost;
		black[b].val-=cost;
		if(w==white.size()-1&&b==black.size()-1) break;
		if(white[w].val==0&&w!=white.size()-1) w++;
		else if(black[b].val==0&&b!=black.size()-1) b++;
	}
	for(int i=0;i<N-1;i++)
	{
		printf("%d %d %d\n",ans[i].u,ans[i].v,ans[i].val);
	}
	return 0;
}