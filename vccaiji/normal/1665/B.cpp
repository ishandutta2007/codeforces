#include<bits/stdc++.h>
using namespace std;
map<int,int> a;
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		int maxx=0;
		cin>>n;
		a.clear();
		for(int i=1;i<=n;i++){
			int aa;
			cin>>aa;
			a[aa]++;
			maxx=max(maxx,a[aa]);
		}int i=0;
		for(;;i++){
			if((maxx<<i)>=n)break;
		}
		cout<<i+n-maxx<<endl;
	}
	return 0; 
}