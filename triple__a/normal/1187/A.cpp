#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int k=b+c-a;
		b-=k,c-=k;
		printf("%d\n",max(b,c)+1);
	}
	return 0;
}