#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=100050;
const int mod=1e9+7;
#define mp make_pair
pair<int,int> p[N];
void Init(){ for(int i=0;i<N;i++) p[i]=mp(i,0);}
pair<int,int> operator + (pair<int,int> a, pair<int,int> b){ a.first=b.first;a.second+=b.second;a.second%=mod;return a;}
pair<int,int> Find(int x){ return p[x].first==x?mp(x,0):p[x]=p[x]+Find(p[x].first);}
int sum;
int main()
{
	int n,i,u,x,sz;
	Init();
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&sz);
		while(sz--)
		{
			scanf("%i %i",&u,&x);
			if(x<0) x+=mod;
			pair<int,int> tmp=Find(u);
			int par=tmp.first;
			int w=tmp.second+x;
			if(w>=mod) w-=mod;
			p[par]=mp(i,w);
			sum+=w;
			if(sum>=mod) sum-=mod;
		}
	}
	printf("%i\n",sum);
	return 0;
}