#include <stdio.h>
#include <algorithm>
int a[6666],b[6666],n;
__int64 f[6666];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){scanf("%d",&a[i]);b[i]=a[i];}
	std::sort(b,b+n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		f[j]+=abs(a[i]-b[j]);
		f[j]=j&&f[j-1]<f[j]?f[j-1]:f[j];
	}
	printf("%I64d\n",f[n-1]);
}