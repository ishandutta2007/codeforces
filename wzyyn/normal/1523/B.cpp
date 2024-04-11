#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%*d");
	printf("%d\n",3*n);
	for (int i=1;i<=n;i+=2){
		printf("2 %d %d\n",i,i+1);
		printf("1 %d %d\n",i,i+1);
		printf("2 %d %d\n",i,i+1);
		printf("2 %d %d\n",i,i+1);
		printf("1 %d %d\n",i,i+1);
		printf("2 %d %d\n",i,i+1);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
x y
x y-x
y y-x
y -x

x y z
x
*/