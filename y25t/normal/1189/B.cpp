#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100005

int n,a[N];

inline bool cmp(int x,int y){
	return x>y;
}

int ans[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	if(a[1]>=a[2]+a[3]){
		printf("NO");
		return 0;
	}
	ans[1]=a[1];
	int i=2,j=n,k=2;
	while(i<=j){
		ans[i++]=a[k++];
		if(i>j)
			break;
		ans[j--]=a[k++];
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}