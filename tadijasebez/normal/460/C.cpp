#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=200050;
const int inf=1e9+69;
int min(int a, int b){ return a>b?b:a;}
int a[N],b[N],n,m,w;
vector<int> c;
int BIT[N];
void init(){ for(int i=0;i<N;i++) BIT[i]=0;}
void Set(int i, int x){ for(;i;i-=i&-i) BIT[i]+=x;}
int Get(int i){ int ret=0;for(;i<N;i+=i&-i) ret+=BIT[i];return ret;}
bool Check(int mid)
{
	int i,r=m;
	c.clear();
	init();
	for(i=1;i<=n;i++) if(a[i]<mid) b[c.size()]=a[i],c.push_back(i);
	for(i=0;i<c.size();i++)
	{
		b[i]+=Get(c[i]);
		if(b[i]<mid)
		{
			int dif=mid-b[i];
			r-=dif;
			if(r<0) return false;
			Set(c[i]+w-1,dif);
		}
	}
	return true;
}
int main()
{
	int i,naj=inf;
	scanf("%i %i %i",&n,&m,&w);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),naj=min(naj,a[i]);
	int top=naj+m,bot=naj,mid,sol;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(Check(mid)) sol=mid,bot=mid+1;
		else top=mid-1;
	}
	printf("%i\n",sol);
	return 0;
}