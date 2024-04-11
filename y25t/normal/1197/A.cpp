#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100005

int T;

int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		printf("%d\n",min(a[n-1]-1,n-2));
	}
}