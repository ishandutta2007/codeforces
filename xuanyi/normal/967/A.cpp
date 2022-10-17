#include <cstdio>
const int MAXN=105;

int n,s;
int h[MAXN],m[MAXN],a[MAXN];

int main(){
	scanf("%d%d",&n,&s); s++;
	for (int i=1;i<=n;i++){
		scanf("%d%d",h+i,m+i);
		a[i]=h[i]*60+m[i];
	}
	if (s<=a[1]){printf("%d %d\n",0,0);return 0;}
	for (int i=2;i<=n;i++){
		if ((s<<1)<=a[i]-a[i-1]){
			printf("%d %d\n",(a[i-1]+s)/60,(a[i-1]+s)%60);
			return 0;
		}
	}
	printf("%d %d\n",(a[n]+s)/60,(a[n]+s)%60);
	return 0;
}