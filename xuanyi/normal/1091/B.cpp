#include <cstdio>
#include <algorithm>
using namespace std;

int n;
pair <int,int> a[1005],b[1005];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d%d",&a[i].first,&a[i].second);
	for (int i=1;i<=n;++i) scanf("%d%d",&b[i].first,&b[i].second);
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	printf("%d %d\n",a[1].first+b[n].first,a[1].second+b[n].second);
	return 0;
}