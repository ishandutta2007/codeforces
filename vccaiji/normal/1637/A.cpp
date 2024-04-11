#include<bits/stdc++.h>
using namespace std;
int n;
int a[110000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		bool r=false;
		for(int i=1;i<n;i++){
			if(a[i]>a[i+1]){
				r=true;
				break;
			}
		}
		if(r) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}