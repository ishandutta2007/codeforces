#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T;
void out(int c){
	printf("%d ",c);
	int d=1;
	for(int i=2;i<m;i+=2,d^=1)
		printf("%d %d ",c^d,c^d);
	printf("%d\n",c^d);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		out(0);
		int c=1;
		for(int i=2;i<n;i+=2,c^=1)
			out(c),out(c);
		out(c);
	}
	return 0;
}