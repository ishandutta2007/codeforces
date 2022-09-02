// author: xay5421
// created: Tue Jan  5 23:45:36 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int n,K;
int ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int y;
	scanf("%d",&y);
	return y;
}
void report(int x){
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
int main(){
	scanf("%d%d",&n,&K);
	ask(1);
	for(int i=1,cur=1;i<=n;++i){
		cur+=i;
		cur=(cur-1)%n+1;
		int t=ask(cur);
		if(t!=K){
			if(t>K){
				while(1){
					cur=(cur+n-2)%n+1;
					int p=ask(cur);
					if(p==K){
						report(cur);
					}
				}
			}else{
				while(1){
					cur=cur%n+1;
					int p=ask(cur);
					if(p==K){
						report(cur);
					}
				}
			}
		}
	}
	return 0;
}