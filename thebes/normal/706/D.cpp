#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int N, i, x, t[31*MN][2], p, cnt[31*MN];
queue<int> nxt;

void add(int n){
	int pos = 0;
	for(p=30;p>=0;p--){
		int x=((1<<p)&n)?1:0;
		if(!t[pos][x]){
			t[pos][x] = nxt.front();
			nxt.pop();
		}
		pos = t[pos][x];
		cnt[pos]++;
	}
}

int qu(int n){
	int ret = 0, pos=0;
	for(p=30;p>=0;p--){
		int x=((1<<p)&n)?1:0;
		if(t[pos][!x]) ret+=(1<<p);
		if(t[pos][!x]) pos=t[pos][!x];
		else pos=t[pos][x];
	}
	return ret;
}

void rem(int n){
	int pos=0, pre=0;
	for(p=30;p>=0;p--){
		int x=((1<<p)&n)?1:0;
		pre=pos; pos=t[pos][x];
		if(!(--cnt[pos])){
			t[pre][x]=0;
			nxt.push(pos);
		}
	}
}

int main(){
	for(i=1;i<=30*MN;i++) nxt.push(i);
	add(0);
	for(scanf("%d",&N),i=0;i<N;i++){
		char c; scanf(" %c%d",&c,&x);
		if(c == '+') add(x);
		else if(c == '-') rem(x);
		else printf("%d\n",qu(x));
	}
	return 0;
}