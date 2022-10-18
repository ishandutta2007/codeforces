#include<cstdio>
#include<algorithm>
using namespace std;
#define N 300005

int n,k;

int d[N];

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,tmp;i<=n;i++){
		int a;
		scanf("%d",&a);
		if(i!=1)
			d[i-1]=a-tmp;
		tmp=a;
	}
	sort(d+1,d+n);
	int ans=0;
	for(int i=1;i<=n-k;i++)
		ans+=d[i];
	printf("%d",ans);
}