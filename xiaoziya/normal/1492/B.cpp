#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=100005;
int T,n,top;
int a[maxn],stk[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),top=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=n;i>=1;i--){
			while(top&&a[stk[top]]<=a[i])
				top--;
			stk[++top]=i;
		}
		stk[0]=n+1;
		for(int i=1;i<=top;i++)
			for(int j=stk[i];j<stk[i-1];j++)
				printf("%d ",a[j]);
		puts("");
	}
	return 0;
}