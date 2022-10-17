#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 200005
using namespace std;
int n,d=-1,a[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) if (abs(a[i]-a[i+1])!=1){d=abs(a[i]-a[i+1]); break;}
	if (d==-1){puts("YES");puts("1000000000 1000000000");return 0;}
	if (!d){puts("NO");return 0;}
	for (int i=1;i<n;i++)
		if (a[i]==a[i+1]||a[i]%d==0&&a[i+1]==a[i]+1||a[i+1]%d==0&&a[i]==a[i+1]+1||abs(a[i]-a[i+1])!=1&&abs(a[i]-a[i+1])!=d){
			puts("NO");
			return 0;
		}
	puts("YES");
	printf("1000000000 %d\n",d);
	return 0;
}