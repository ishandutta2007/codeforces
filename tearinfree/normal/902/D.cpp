#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;
typedef long long lli;

int n,a[151],b[151];

int main() {
	scanf("%d",&n);
	a[1]=1; b[0]=1;
	for(int i=1;i<n;i++) {
		int tmp[151]={0,};
		for(int j=0;j<=i;j++) tmp[j+1]+=a[j];
		for(int j=0;j<i;j++) tmp[j]-=b[j];
		for(int j=0;j<=i+1;j++) if( (tmp[j]<0 ? -tmp[j] : tmp[j])>=2 ) {
			for(int j=0;j<=i+1;j++) tmp[j]=0;
			for(int j=0;j<=i;j++) tmp[j+1]=a[j];
			for(int j=0;j<i;j++) tmp[j]+=b[j];
			break;
		}
		for(int j=0;j<=i;j++) b[j]=a[j];
		for(int j=0;j<=i+1;j++) a[j]=tmp[j];
	}
	printf("%d\n",n);
	for(int i=0;i<=n;i++) printf("%d ",a[i]);
	puts("");
	printf("%d\n",n-1);
	for(int i=0;i<n;i++) printf("%d ",b[i]);
	return 0;
}