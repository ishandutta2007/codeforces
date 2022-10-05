#include<bits/stdc++.h>
using namespace std;
int _,n,m;
int p=1000000007;
int main(){
	scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		int o=0;
		for(int i=1;i<=m;i++){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			o|=x;
		}
		o%=p;
		for(int i=1;i<n;i++)o=(o<<1)%p;
		printf("%d\n",o);
	}
	return 0;
}