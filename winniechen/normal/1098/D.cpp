#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
using namespace std;
#define N 500005
#define ll long long
int w[N],p[N],n,sp;char str[10];
multiset<int >s;int siz;ll c[N];
void fix(int x,int v){for(;x<=sp;x+=x&-x)c[x]+=v;}
ll find(int x){ll ret=0;for(;x;x-=x&-x)ret+=c[x];return ret;}
void add(int x){siz++;s.insert(p[x]);fix(x,p[x]);}
void del(int x){siz--;s.erase(s.find(p[-x]));fix(-x,-p[-x]);}
int get_ans()
{
	if(!siz)return 0;
	int ret=1,now=*s.begin();
	while(1)
	{
		if(now>1e9)break;
		if(s.upper_bound(now<<1)!=s.end())
		{
			int t=*s.upper_bound(now<<1);
			t=lower_bound(p+1,p+sp+1,t)-p;
			if(find(t-1)*2<p[t])ret++;now=p[t]+now;
		}else return siz-ret;
	}return siz-ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s%d",str,&p[i]),(str[0]=='+'?(w[i]=p[i]):(w[i]=-p[i]));
	sort(p+1,p+n+1);sp=unique(p+1,p+n+1)-p-1;
	for(int i=1;i<=n;i++)w[i]=(w[i]<0)?-(lower_bound(p+1,p+sp+1,-w[i])-p):lower_bound(p+1,p+sp+1,w[i])-p;
	for(int i=1;i<=n;i++)
		if(w[i]<0)del(w[i]),printf("%d\n",get_ans());
		else add(w[i]),printf("%d\n",get_ans());
}
//     dasdasd