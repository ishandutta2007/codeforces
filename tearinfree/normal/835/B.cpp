#include <cstdio>
#include <algorithm>
#include <cstring>

typedef long long lli;

lli k,arr[100100];
char str[100100];
int n;

int main() {
	lli sum=0;
	scanf("%lld%s",&k,str);
	n=strlen(str);
	for(int i=0;i<n;i++) arr[i]=str[i]-'0',sum+=arr[i];
	std::sort(arr,arr+n);
	int i;
	for(i=0;i<n&&sum<k;i++) {
		sum+=9-arr[i];
	}
	printf("%d\n",i);
	
	return 0;
}