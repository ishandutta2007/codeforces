#include <iostream>
using namespace std;

int a[10], b[10], s, t, n, m, x;

int main(){
	for(scanf("%d%d",&n,&m);n>0;n--){
		scanf("%d",&x); a[x] = 1;
	}
	for(;m>0;m--){
		scanf("%d",&x); b[x] = 1;
	}
	for(int i=1;i<=9;i++){
		if(a[i] && !n) n = i;
		if(b[i] && !m) m = i;
		if(a[i] == b[i] && a[i]){printf("%d\n",i); return 0;}
	}
	printf("%d%d\n",min(n,m),max(n,m));
	return 0;
}