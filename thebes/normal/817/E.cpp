#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,abm,mmx,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN=1e5+5,LG=30;
int t[LG*MN][2], Q, i, cnt[LG*MN], p, x, y, w, nxt;
void add(int n,int d){
	p = 0;
	for(int i=LG-1;i>=0;i--){
		int dr=((1<<i)&n)?1:0;
		if(!t[p][dr]) t[p][dr]=++nxt;
		p=t[p][dr];cnt[p]+=d;
	}
}
int qu(int n,int d){
	p=0; int ret=0;
	for(int i=LG-1;i>=0;i--){
		int a=((1<<i)&n)?1:0;
		int b=((1<<i)&d)?1:0;
		if(b) ret+=cnt[t[p][a]];
		if(!t[p][a^b]) return ret;
		p=t[p][a^b];
	}
	return ret+cnt[p];
}

int main(){
	for(scanf("%d",&Q);Q;Q--){
		scanf("%d%d",&i,&x);
		if(i!=3) add(x,(i==1)?1:-1);
		else{
			scanf("%d",&y);y--;
			printf("%d\n",qu(x,y));
		}
	}
	return 0;
}