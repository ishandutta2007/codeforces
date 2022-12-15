#include <bits/stdc++.h>
using namespace std;

const int MN=3e5+5,LG=30;
int N, i, arr[MN], t[LG*MN][2], v[LG*MN], x, p, nxt;

void cmp(int val, int dt){
	int p=0; v[0]+=dt;
	for(int i=LG-1;i>=0;i--){
		int d=((1<<i)&val)?1:0;
		if(!t[p][d]) t[p][d]=++nxt;
		p = t[p][d]; v[p]+=dt;
	}
}

int qu(int val){
	int p=0, ret=0;
	for(int i=LG-1;i>=0;i--){
		int d=((1<<i)&val)?1:0;
		if(t[p][d]&&v[t[p][d]])	p=t[p][d];
		else ret+=(1<<i),p=t[p][!d];
	}
	return ret;
}

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=N;i++){
		scanf("%d",&x);
		cmp(x, 1);
	}
	for(i=1;i<=N;i++){
		int tmp=qu(arr[i]);
		cmp(tmp^arr[i], -1);
		printf("%d ",tmp);
	}
	return 0;
}