#include<stdio.h>
int main()
{
	int n, d=0, t;
	char s[100];
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d%s", &t, s);
		if(s[0] == 'N'){
			d -= t;
		}
		else if(s[0] == 'S'){
			d += t;
		}
		else{
			if(d==0 || d==20000){
				printf("NO");
				return 0;
			}
		}
		if(d<0 || d>20000){
			printf("NO");
			return 0;
		}
	}
	if(d!=0) printf("NO");
	else printf("YES");
	return 0;
}