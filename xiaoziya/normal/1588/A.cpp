#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=105;
int T,n;
int a[maxn],b[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		sort(a+1,a+1+n),sort(b+1,b+1+n);
		int flg=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i]&&b[i]-a[i]!=1){
				flg=1;
				break;
			}
		if(flg==0)
			puts("YES");
		else puts("NO");
	}
	return 0;
}