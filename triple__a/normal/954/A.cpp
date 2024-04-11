#include "bits/stdc++.h"
using namespace std;

const int maxn=107;
int main(){
	int n,ans;
	char s[maxn];
	scanf("%d",&n);
	ans=n;
	scanf("%s",&s);
	for (int i=0;i<n;++i){
		if (s[i]!=s[i+1]&&i+1<n){
			ans--;
			i++;
		} 
	}
	printf("%d\n",ans);
	return 0;
}