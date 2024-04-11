#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,A[110];
int check(int K){
	int k1=0,k2=0;
	for (int i=1;i<=n;i++) k1+=A[i],k2+=K-A[i];
	return k2>k1;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	int now=0;
	for (int i=1;i<=n;i++) now=max(now,A[i]);
	while (check(now)==0) now++;
	cout<<now<<endl;
}