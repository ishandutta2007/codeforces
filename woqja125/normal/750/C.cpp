#include<stdio.h>
int l[2];
int main()
{
	int n, c, d, i, b = 0;
	scanf("%d", &n);
	l[0] = 2147483647;
	l[1] = -2147483647;
	for(int i=1; i<=n; i++){
		scanf("%d%d", &c, &d);
		if(d==1){
			if(l[0] > b) l[0] = b;
		}
		else{
			if(l[1] < b) l[1] = b;
		}
		b+=c;
	}
	if(l[0] <= l[1]) printf("Impossible");
	else if(l[1] == -2147483647) printf("Infinity");
	else printf("%d", b-l[1]+1899);
	return 0;
}