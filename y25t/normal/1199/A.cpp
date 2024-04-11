#include<cstdio>
#define N 100005

int n,x,y,a[N];

int main(){
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		bool flg=1;
		for(int j=i-1;j&&i-j<=x;j--)
			if(a[j]<a[i])
				flg=0;
		for(int j=i+1;j<=n&&j-i<=y;j++)
			if(a[j]<a[i])
				flg=0;
		if(flg){
			printf("%d",i);
			return 0;
		}
	}
}