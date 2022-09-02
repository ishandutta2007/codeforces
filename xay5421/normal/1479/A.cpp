// author: xay5421
// created: Sun Feb  7 22:37:53 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005;
int n,a[N];
int ask(int x){
	if(a[x]!=-1)return a[x];
	printf("? %d\n",x),fflush(stdout);
	int y;
	scanf("%d",&y);
	return a[x]=y;
}
void chk(int x){
	if(ask(x-1)>ask(x)&&ask(x)<ask(x+1)){
		printf("! %d\n",x);
		exit(0);
	}
}
int main(){
	memset(a,-1,sizeof(a));
	scanf("%d",&n);
	a[0]=1e9,a[n+1]=1e9;
	chk(1),chk(n);
	int now=1;
	per(i,20,0)if(now+(1<<i)<=n){
		if(ask(now+(1<<i)-1)>ask(now+(1<<i))&&ask(now+(1<<i))<=ask(now)-(1<<i)){
			now+=1<<i;
			chk(now);
		}
	}
	assert(0);
	return 0;
}