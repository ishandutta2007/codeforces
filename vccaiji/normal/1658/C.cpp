#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int c[210000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&c[i]);
		int cnt=0,j;
		for(int i=1;i<=n;i++){
			if(c[i]==1){
				cnt++;
				j=i;
			}
		}
		if(cnt!=1){
			cout<<"NO\n";
			continue;
		}
		bool r=1;
		for(int i=j%n+1;i!=j;i=i%n+1){
			int o=(i+n-2)%n+1;
			if((c[i]<2)||(c[i]>c[o]+1)){
				r=0;
				break;
			}
		}
		if(r) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}