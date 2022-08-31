#include <bits/stdc++.h>
using namespace std;
int n;
int x[110000],y[110000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++) y[x[i]]++;
	for (int i=1;i<=100000;i++)
		if (y[i]&1){
			printf("Conan\n"); return 0;
		}
	printf("Agasa\n"); return 0;
}