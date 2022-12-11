#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int max_m=500;
bool vis[max_m+1];
int m;
int query(const int x){
	vis[x]=1;
	putchar('?');
	putchar(' ');
	for(int i=1; i<=m; ++i)
		putchar(vis[i]|'0');
	putchar('\n');
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int querypos(const int x){
	const int ans=query(x);
	vis[x]=0;
	return ans;
}
pair<int,int> a[max_m+1];
int main(){
	scanf("%*d%d",&m);
	memset(vis+1,0,m);
	for(int i=1; i<=m; ++i)
		a[i].first=querypos(i),a[i].second=i;
	sort(a+1,a+m+1);
	int ans=a[1].first;
	memset(vis+1,0,m);
	vis[a[1].second]=1;
	for(int i=2,lst=ans; i<=m; ++i){
		const int l=a[i].first,t=query(a[i].second);
		if(lst+l==t)
			ans+=l;
		lst=t;
	}
	printf("! %d\n",ans);
	return 0;
}