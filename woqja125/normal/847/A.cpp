#include<stdio.h>
int l[101];
int r[101];
int end(int x){
	while(r[x]) x = r[x];
	return x;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d%d", l+i, r+i);
	}
	int p = 0;
	for(int i=1; i<=n; i++){
		if(l[i] == 0){
			int x = end(i);
			if(p!=0){
				l[i] = p;
				r[p] = i;
			}
			p = x;
		}
	}
	for(int i=1; i<=n; i++) printf("%d %d\n", l[i], r[i]);
	return 0;
}