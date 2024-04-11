#include<cstdio>
#include<algorithm>
#define N 100005

int T;

int n,a[N<<1];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=(n<<1);i++)
			scanf("%d",&a[i]);
		std::sort(a+1,a+(n<<1)+1);
		printf("%d\n",a[n+1]-a[n]);
	}
}