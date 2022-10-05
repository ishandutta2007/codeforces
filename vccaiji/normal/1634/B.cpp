#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	int n,x;
	long long y;
	while(t--){
		scanf("%d%d%lld",&n,&x,&y);
		int sum=0;
		for(int i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			sum^=a;
		}
		if((x+y)%2==sum%2) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}