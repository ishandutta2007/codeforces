#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,arr[100001];

int main() {
	scanf("%d",&n);
	n++;
	for(int i=0;i<n;i++) scanf("%d",arr+i);

	int flag=0;
	for(int i=0;i<n-1;i++) {
		if(arr[i]>=2 && arr[i+1]>=2) {
			flag=1;
			break;
		}
	}
	if(flag==0) {
		puts("perfect");
		return 0;
	}
	puts("ambiguous");
	int p=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<arr[i];j++) printf("%d ",p);
		p+=arr[i];
	}
	p=0; flag=0;
	puts("");
	for(int i=0;i<n;i++) {
		if(i!=0 && !flag && arr[i]>=2 && arr[i-1]>=2) {
			printf("%d %d ",p,p-1);
			for(int j=2;j<arr[i];j++) {
				printf("%d ",p);
			}
			flag=1;
		} 
		else {
			for(int j=0;j<arr[i];j++) {
				printf("%d ",p);
			}
		}
		p+=arr[i];
	}
	return 0;
}