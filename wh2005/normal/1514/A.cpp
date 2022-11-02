#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int T,n,a[N];


int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int flag=1;
		for(int i=1;i<=n;i++){
			int t=sqrt(a[i]);
			if(t*t!=a[i]) flag=0;
		}	
		if(!flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}