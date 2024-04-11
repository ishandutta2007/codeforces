#include<cstdio>
#define N 200005

int T;

int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bool flg=1;
	for(int i=1;i<=n;i++)
		if(a[i]!=a[1]){
			flg=0;
			break;
		}
	printf("%d\n",flg?n:1);
	}
}