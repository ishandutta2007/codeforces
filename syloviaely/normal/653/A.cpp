#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,pd[1100],lim=1000;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1); pd[k1]=1;
	}
	for (int i=1;i<=lim;i++) if (pd[i]&&pd[i-1]&&pd[i+1]){
		printf("YES\n"); return 0;
	}
	printf("NO\n"); return 0;
}