using namespace std;
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define N 10001
int n,a[N],b[N];
bool flag=0;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	if(a[1]!=b[1]) {
		puts("rated");return 0;
	}
	for(int i=2;i<=n;i++) {
		if(a[i]!=b[i]) {
			puts("rated");return 0;
		}
		if(a[i]>a[i-1]) {
			flag=1;
		}
	}
	if(flag) {
		puts("unrated");
	}
	else puts("maybe");
}