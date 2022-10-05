#include<bits/stdc++.h>
using namespace std;
int a[1100000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		map<int,int> mp;
		for(int i=1;i<=n;i++) mp[a[i]]++;
		bool r=0;
		for(int i=1;i<=n;i++){
			if(mp.count(a[i]+k)){
				r=1;
				break;
			}
		}
		if(r) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}