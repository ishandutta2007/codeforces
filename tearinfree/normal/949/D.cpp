#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

int n,d,b,arr[100000],a[100000];

bool check(int num) {
	for(int i=0;i<n;i++) arr[i]=a[i];

	int i=0,j=0,k=0,s=0,cnt=0;
	for(;i<=(n-1)/2; i++) {
		for(;j<n && j<=i+(i+1)*d;j++) s += arr[j];
		if(s>=b) {
			int t=b;
			for(;k<n && k<=i+(i+1)*d;k++) {
				if(arr[k] >= t) {
					arr[k] -= t;
					break;
				}
				t-=arr[k];
				arr[k]=0;
			}
			s-=b;
		}
		else cnt++;
		if(cnt > num) return false;
	}

	int bo=i;
	i=n-1;j=n-1;k=n-1;s=0;cnt=0;
	for(;i>=bo; i--) {
		for(;j>=0 && j>=i-(n-i)*d;j--) s+=arr[j];
		if(s>=b) {
			int t=b;
			for(;k>=0 && k>=i-(n-i)*d;k--) {
				if(arr[k] >= t) {
					arr[k] -= t;
					break;
				}
				t-=arr[k];
				arr[k]=0;
			}
			s-=b;
		}
		else cnt++;
		if(cnt > num) return false;
	}
	return true;
}
int main() {
	scanf("%d%d%d",&n,&d,&b);
	for(int i=0;i<n;i++) scanf("%d",a+i);

	int lo=-1,up=(n-1)/2;
	while(up-lo>1) {
		int md=(lo+up)>>1;
		if(check(md)) up=md;
		else lo=md;
	}
	
	printf("%d\n",up);
	
	return 0;
}