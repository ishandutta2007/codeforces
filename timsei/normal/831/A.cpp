using namespace std;
#include<cstdio>
#include<iostream>
int a[10001];
int n;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int up=1;a[0]=-99999999;
	while(1) {
		if(up==n+1) {
			puts("YES");return 0;
		}
		if(a[up]>a[up-1]) up++;else break;
	}
	int mid=up+1;
	if(a[mid-2]==a[mid-1])
	{
		while(1) {
			if(mid==n+1) {
				puts("YES");return 0;
			}
			if(a[mid]==a[mid-1]) mid++;else break;
		}		
	}
	if(mid==n+1) {
		puts("YES");return 0;
	}
	if(a[mid]>=a[mid-1]) {
		puts("NO");return 0;
	}
	int last=mid+1;
	while(1) {
		if(last==n+1) {
			puts("YES");return 0;
		}
		if(a[last]<a[last-1]) last++;else {
			puts("NO");return 0;
		}
	}
}