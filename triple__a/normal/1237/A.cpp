#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;
int n,a[maxn];

int main(){
	scanf("%d",&n);
	bool fg=false;
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
		if (a[i]%2){
			a[i]=(a[i]+1)/2;
			if (fg){
				a[i]--;
			}
			fg=1-fg;
		}
		else{
			a[i]/=2;
		}
	}
	for (int i=0;i<n;++i){
		printf("%d\n",a[i]);
	}
	return 0;
}