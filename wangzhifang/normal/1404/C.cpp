#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
#define max_n 300000
int a[max_n+1],b[max_n+1],c[max_n+1];
vector<pii>que[max_n+1];
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; ++i){
		scanf("%d",a+i);
		a[i]=(i<a[i]?-n:a[i]-i);
	}
	for(int i=q,x,y; i; --i){
		scanf("%d%d",&x,&y);
		que[y+1].push_back(make_pair(n-x,i));
	}
	reverse(a+1,a+n+1);
	for(int y=n+1,i=0; --y; i=0){
		for(int j=1<<19; (j>>=1)&&i<=n&&a[y]<0; i+j<=n&&a[y]+b[i+j]<0&&(a[y]+=b[i+=j]));
		for(y>++i&&(i=y); i<=n; ++b[i],i+=i&-i);
		for(int j=que[y].size(); --j>=0; )
			for(i=que[y][j].first; i; c[que[y][j].second]+=b[i],i^=i&-i);
	}
	for(; q; --q)
		printf("%d\n",c[q]);
	return 0;
}