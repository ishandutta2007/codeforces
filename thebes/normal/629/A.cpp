#include <bits/stdc++.h>
using namespace std;

int n, r[101], c[101], i, j, ans;

int main(){
	for(scanf("%d",&n),i=0;i<n;i++){
		getchar();
		for(j=0;j<n;j++){
			char ch; ch=getchar();
			if(ch=='C') r[i]++,c[j]++;
		}
	}
	for(i=0;i<n;i++) ans += (r[i]*(r[i]-1)/2+c[i]*(c[i]-1)/2);
	printf("%d\n",ans);
	return 0;
}