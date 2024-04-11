// author: xay5421
// created: Sun Oct 17 19:24:02 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=105;
int n,pre[N],nex[N];
int main(){
	scanf("%d",&n);
	per(i,n,1){
		printf("? ");
		rep(j,1,n)printf("%d ",1+(i==j));
		puts("");
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if(x!=0&&x!=i){
			nex[i]=x;
			pre[x]=i;
		}
		printf("? ");
		rep(j,1,n)printf("%d ",2-(i==j));
		puts("");
		fflush(stdout);
		scanf("%d",&x);
		if(x!=0&&x!=i){
			nex[x]=i;
			pre[i]=x;
		}
	}
	int fir=-1;
	rep(i,1,n)if(!pre[i])fir=i;
	vector<int>p(n+1);
	int ind=0;
	for(int i=fir;i;i=nex[i]){
		p[i]=++ind;
	}
	printf("! ");
	rep(i,1,n)printf("%d " ,p[i]);
	fflush(stdout);
	return 0;
}