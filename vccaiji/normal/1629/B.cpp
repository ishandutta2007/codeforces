#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	for(int pp=0;pp<T;pp++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		if(r==l){
			if(l==1) printf("NO\n");
			else printf("YES\n");
			continue;
		}
		if(r-l+1-k<=r/2-(l-1)/2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}