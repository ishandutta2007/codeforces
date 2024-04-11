#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 2e5;
 
int p[N+5],sg[N+5],n,f,x,y,z,ans,cnt=0;
bitset<N+5> lv1,lv[100];
 
int main(){
	rep(i,2,N)p[i]=i;
	rep(i,2,N){
		rep(j,i,N/i)p[j*i]=p[i];
		x=i/p[i];
		if(x==1||x==p[x])lv1[i]=1;
	}
	scanf("%d%d",&n,&f);
	lv1[f]=0;
	rep(i,0,N){
		while(lv[sg[i]][i])++sg[i];
		lv[sg[i]]|=lv1<<i;
	}
	rep(i,1,n)scanf("%d%d%d",&x,&y,&z),ans^=sg[y-x-1]^sg[z-y-1];
	puts(ans?"Alice\nBob":"Bob\nAlice");
	return 0; 
}