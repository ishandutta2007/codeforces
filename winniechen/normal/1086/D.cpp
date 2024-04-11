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
#define N 200005
struct BIT
{
	int s[N];
	void fix(int x,int op){for(;x<N;x+=x&-x)s[x]+=op;}
	int find(int x){int ret=0;for(;x;x-=x&-x)ret+=s[x];return ret;}
	int get(int l,int r){return find(r)-find(l-1);}
}b[3];
set<int>s[3];
int a[128],n,Q;
char str[N],opt[3];
int calc()
{
	int ans=0;
	for(int i=0;i<3;i++)
	{
		if(s[(i+1)%3].empty()){ans+=s[i].size();continue;}
		if(s[(i+2)%3].empty())continue;
		int L=*s[(i+2)%3].begin(),R=*(--s[(i+2)%3].end());
		ans+=b[i].get(L,R);
		int X=*s[(i+1)%3].begin(),Y=*(--s[(i+1)%3].end());
		ans+=b[i].find(min(L,X)-1)+b[i].get(max(R,Y)+1,n);
	}
	return ans;
}
int main()
{
	a['R']=0;a['P']=1;a['S']=2;
	scanf("%d%d%s",&n,&Q,str+1);
	for(int i=1;i<=n;i++)s[a[str[i]]].insert(i),b[a[str[i]]].fix(i,1);
	printf("%d\n",calc());
	while(Q--)
	{
		int x;scanf("%d%s",&x,opt);
		s[a[str[x]]].erase(x);b[a[str[x]]].fix(x,-1);
		str[x]=opt[0];
		s[a[str[x]]].insert(x),b[a[str[x]]].fix(x,1);
		printf("%d\n",calc());
	}
}