#include <bits/stdc++.h>
using namespace std;

int cost[8], n, i, c, msk;
string s;

int main(){
	for(int i=1;i<8;i++)
		cost[i] = 1<<30;
	for(scanf("%d",&n),i=1;i<=n;i++){
		cin >> c >> s; msk = 0;
		for(char ch : s){
			if(ch=='A') msk |= 1;
			if(ch=='B') msk |= 2;
			if(ch=='C') msk |= 4;
		}
		for(int w=0;w<8;w++)
			cost[msk|w]=min(cost[msk|w],cost[w]+c);
	}
	printf("%d\n",cost[7]==1<<30?-1:cost[7]);
	return 0;
}