#include<bits/stdc++.h>

using namespace std;

int n,k,a[20];

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=0,y;j<k;j++){
			scanf("%d",&y);if(y)x+=1<<j;
		}
		a[x]++;
	}
	for(int i=0;i<16;i++)for(int j=0;j<16;j++) if((i&j)==0&&a[i]&&a[j]) puts("YES"),exit(0);
	puts ("NO"); 
	return 0;
}