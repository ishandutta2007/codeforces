#include<bits/stdc++.h>

using namespace std;

#define rg register

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(n == 1)puts("-1");
		else{
			int x = n - 1;
			if(x % 3 == 0)x--;
			for(rg int i = 1;i <= x;i++)putchar('2');
			for(rg int i = x + 1;i <= n;i++)putchar('3');
			putchar('\n');
		}
	}
	return 0;
}