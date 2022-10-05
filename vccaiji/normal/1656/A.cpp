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
		int minn=a[1],j=1;
		int maxx=a[1],j2=1;
		for(int i=2;i<=n;i++){
			if(a[i]>maxx){
				maxx=a[i];
				j2=i;
			}
			if(a[i]<minn){
				minn=a[i];
				j=i;
			}
		}
		cout<<j<<' '<<j2<<endl;
	}
	return 0;
}