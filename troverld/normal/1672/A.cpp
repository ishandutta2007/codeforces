#include<bits/stdc++.h>
using namespace std;
int T,n;
void mina(){
	int sum=0;
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),sum+=x-1;
	if(sum&1)puts("errorgorn");else puts("maomao90");
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}