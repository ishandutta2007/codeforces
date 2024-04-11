#include "bits/stdc++.h"
using namespace std;

const int maxn=107;
int main(){
	int n,ans;
	char s[maxn];
	scanf("%d",&n);
	ans=0;
	scanf("%s",&s);
	for (int i=0;i<n;++i){
		int j=i+1,k=0;
		while (k<=i){
			if (j>=n||s[j]!=s[k]) break;
			j++,k++;
		}
		if (k>i) ans=i;
	}
	printf("%d\n",n-ans);
	return 0;
}