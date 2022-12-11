#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int k=abs(a+b-c*2);
		if(k%3==0)printf("0\n");
		else printf("1\n");
	}
	return 0;
}