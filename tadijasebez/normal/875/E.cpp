#include <stdio.h>
#include <set>
using namespace std;
const int N=100050;
int x[N],s1,s2,n;
int abs(int x){ return x>0?x:-x;}
set<int> ord;
bool Check(int mid)
{
	if(abs(s1-s2)>mid) return 0;
	ord.clear();
	ord.insert(s1);
	ord.insert(s2);
	for(int i=1;i<=n;i++)
	{
		if(i!=1) ord.insert(x[i-1]);
		while(ord.size() && abs(*ord.begin()-x[i])>mid) ord.erase(ord.begin());
		while(ord.size() && abs(*ord.rbegin()-x[i])>mid) ord.erase(--ord.end());
		if(ord.empty()) return 0;
	}
	return 1;
}
int main()
{
	scanf("%i %i %i",&n,&s1,&s2);
	for(int i=1;i<=n;i++) scanf("%i",&x[i]);
	int top=1e9+7,bot=0,mid,ans;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(Check(mid)) ans=mid,top=mid-1;
		else bot=mid+1;
	}
	printf("%i\n",ans);
	return 0;
}