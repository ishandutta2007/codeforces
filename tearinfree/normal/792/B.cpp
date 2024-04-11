#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> ip;

int n,k,arr[1000],t[100];

int main() {
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)scanf("%d",arr+i);
	for(int i=0;i<n;i++) t[i]=i+1;

	int cur=0;
	for(int i=0;i<k;i++) {
		cur=(cur+arr[i])%(n-i);
		printf("%d ",t[cur]);
		for(int j=cur;j<n-i;j++) t[j]=t[j+1];
	}
	return 0;
}