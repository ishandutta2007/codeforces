#include<cstdio>
#define N 100005

int n,a[N];

int cnt[32];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<31;j++)
			cnt[j]+=(a[i]>>j)&1;
	int id=0,val=0;
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=0;j<31;j++)
			if(((a[i]>>j)&1)&&cnt[j]==1)
				tmp|=(1<<j);
		if(tmp>=val){
			id=i;
			val=tmp;
		}
	}
	printf("%d ",a[id]);
	for(int i=2;i<=n;i++)
		printf("%d ",a[i==id?1:i]);
}