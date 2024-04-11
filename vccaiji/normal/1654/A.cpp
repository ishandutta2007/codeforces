#include<bits/stdc++.h>
using namespace std;
int a[110000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int aa=0,bb=0;
		for(int i=1;i<=n;i++){
			if(aa<a[i]){
				bb=aa;
				aa=a[i];
			}
			else bb=max(bb,a[i]);
		}
		cout<<aa+bb<<endl;
	}
	return 0;
}