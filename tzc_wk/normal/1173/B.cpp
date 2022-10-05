#include <bits/stdc++.h>
int n;
using namespace std;
int main(){
	scanf("%d",&n);
	printf("%d\n",n/2+1);
	int cnt=n;
	for(int i=1;i<=n/2+1;i++){
		if(cnt>0)
			printf("%d %d\n",1,i),cnt--;
	}
	for(int i=2;i<=n/2+1;i++){
		if(cnt>0)
			printf("%d %d\n",i,n/2+1),cnt--;
	}
	return 0;
}