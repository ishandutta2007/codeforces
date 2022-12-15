#include <bits/stdc++.h>
using namespace std;

const int MN = 100005;
int H, i, x, p=1, n, v; vector<int> a[2];

int main(){
	for(scanf("%d",&H),i=0;i<H+1;i++){
		scanf("%d",&x);
		a[0].push_back(n);
		if(x > 1 && p > 1)
			a[1].push_back(n-1), v=1;
		else a[1].push_back(n);
		for(int j=0;j<x-1;j++)
			a[0].push_back(n),a[1].push_back(n);
		n += x; p = x;
	}
	if(v){
		printf("ambiguous\n");
		for(int i=0;i<2;i++){
			for(int v : a[i])
				printf("%d ",v);
			printf("\n");
		}
	}
	else printf("perfect\n");
	return 0;
}