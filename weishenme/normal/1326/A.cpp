#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		if (n==1)puts("-1");
		else {
			if (2*(n-1)%3==0){
				for (int i=1;i<=n-2;i++)putchar('2');
				putchar('3');putchar('3');
				puts("");
			}
			else {
				for (int i=1;i<n;i++)putchar('2');
				puts("3");
			}
		}
	}
}