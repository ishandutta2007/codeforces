#include<bits/stdc++.h>
using namespace std;
int a[1100000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		map<int,int> mp;
		for(int i=1;i<=n;i++) mp[a[i]]++;
		if(!mp.count(1)){
			printf("YES\n");
			continue;
		} 
		bool r=0;
		for(int i=1;i<=n;i++)if(mp.count(a[i]+1)) {
			r=1;
			break;
		}
		if(r) printf("NO\n");
		else printf("YES\n"); 
	}
	return 0;
}