#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;scanf("%i",&t);
	while(t--){
		int n,k;scanf("%i %i",&n,&k);
		int bal=0,las=0,mn=1e9;
		bool ok1=0,ok2=0;
		for(int i=1;i<=n;i++){
			int x;scanf("%i",&x);
			if(x==k)ok1=1;
			las=bal;bal+=x>=k?1:-1;
			if(bal-mn>0)ok2=1;
			mn=min(mn,las);
		}
		printf(ok1&&(n==1||ok2)?"yes\n":"no\n");
	}
	return 0;
}