#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,x[210000],A[210000];
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&x[i]);
	for (int i=1;i<n;i++){
		int next=0;
		for (int j=1;j<i;j=next+1){
			next=(i-1)/((i-1)/j);
			if (x[(i-1)/j]>x[i]){
				A[j]++; A[next+1]--;
			}
		}
		if (x[0]>x[i]){A[i]++; A[n]--;}
	}
	for (int i=1;i<n;i++) A[i]+=A[i-1];
	for (int i=1;i<n;i++) printf("%d ",A[i]);
	return 0;
}