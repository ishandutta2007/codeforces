#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=500005;
int n;
int a[maxn],cnt[maxn];
int main(){
	scanf("%d",&n);
	cnt[0]=n;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x),x=(x==4? 1:(x==8? 2:(x==15? 3:(x==16? 4:(x==23? 5:6)))));
		if(cnt[x-1])
			cnt[x-1]--,cnt[x]++;
	}
	printf("%d\n",n-cnt[6]*6);
	return 0;
}