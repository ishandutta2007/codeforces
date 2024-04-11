#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct atom{
	int where,s;
};
queue<atom>Q;
vector<int>A[2100000];
int n,N,L[110000],R[110000],len;
char ch[1100000];
int main(){
	scanf("%d",&N);
	for (int i=1;i<=N;i++){
		L[i]=len+1; scanf("%s",ch+L[i]);
		len+=strlen(ch+L[i]);
		R[i]=len;
		int K; scanf("%d",&K);
		for (;K;K--){
			int k1; scanf("%d",&k1); A[k1].push_back(i); n=max(n,k1+R[i]-L[i]);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<A[i].size();j++) Q.push((atom){A[i][j],i});
		while (!Q.empty()){
			atom k=Q.front(); if (i>k.s+R[k.where]-L[k.where]) Q.pop(); else break;
		}
		if (Q.empty()) putchar('a'); else{
			atom k=Q.front(); putchar(ch[L[k.where]+i-k.s]);
		}
	}
	putchar('\n');
	return 0;
}