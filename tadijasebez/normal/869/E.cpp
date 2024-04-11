#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <time.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mp make_pair
const int N=2505;
ll BIT[N][N];
void Set(int x, int y, ll w){ for(int i=x;i<N;i+=i&-i) for(int j=y;j<N;j+=j&-j) BIT[i][j]^=w;}
void Set(int x1, int y1, int x2, int y2, ll w){ x2++,y2++,Set(x1,y1,w),Set(x2,y1,w),Set(x1,y2,w),Set(x2,y2,w);}
ll Get(int x, int y){ ll ans=0;for(int i=x;i;i-=i&-i) for(int j=y;j;j-=j&-j) ans^=BIT[i][j]; return ans;}
map<pair<pii,pii>,ll> Hash;
int main()
{
	int n,m,q,t,x1,x2,y1,y2;
	scanf("%i %i %i",&n,&m,&q);
	while(q --> 0)
	{
		scanf("%i %i %i %i %i",&t,&x1,&y1,&x2,&y2);
		srand(time(NULL));
		if(t==1) Hash[mp(mp(x1,y1),mp(x2,y2))]=(q+1)*(rand()*rand())^rand()-rand();
		if(t==3) Get(x1,y1)==Get(x2,y2)?printf("Yes\n"):printf("No\n");
		else Set(x1,y1,x2,y2,Hash[mp(mp(x1,y1),mp(x2,y2))]);
	}
	return 0;
}