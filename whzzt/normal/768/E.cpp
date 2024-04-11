#include"bits/stdc++.h"
using namespace std;
const int N=1000005;
int n,s[N],a,b,res;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);int x;
		for(x=1;x*(x+1)/2<=s[i];x++);
		res^=--x;
	}
	puts(res?"NO":"YES");
	return 0;
}