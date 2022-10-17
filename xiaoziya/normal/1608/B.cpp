#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
const int maxn=100005;
int T,n,a,b,anss;
int ans[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&a,&b);
		if(abs(a-b)>1){
			puts("-1");
			continue;
		}
		if(a==b){
			if(a*2+2>n){
				puts("-1");
				continue;
			}
			for(int i=1;i<=a+1;i++)
				printf("%d %d ",i,a+1+i);
			for(int i=2*a+3;i<=n;i++)
				printf("%d ",i);
			puts("");
			continue;
		}
		anss=0;
		int flg=0;
		if(a>b)
			swap(a,b),flg=1;
		if(2*b+1>n){
			puts("-1");
			continue;
		}
		for(int i=1;i<=b;i++)
			ans[++anss]=b+i,ans[++anss]=i;
		for(int i=2*b+1;i<=n;i++)
			ans[++anss]=i;
		for(int i=1;i<=n;i++)
			printf("%d%c",flg==0? ans[i]:n-ans[i]+1,i==n? '\n':' ');
	}
	return 0;
}