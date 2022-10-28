#include<stdio.h>
int main(){
	int n,k,g,t;
	scanf("%d%d\n",&n,&k);
	char a[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%c",&a[i]);
		if(a[i]=='G') g = i;
		if(a[i]=='T') t = i;
	}
	if(g==t) {
		printf("YES");
		return 0;
	}
	else if (g>t) {
		if((g-t)%k!=0) {
			printf("NO");
			return 0;
		}
		else{
			int i = g;
			while(i!=t){
				i = i-k;
				if ((a[i]!='.')&&(a[i]!='T')){
					printf("NO");
					return 0;
				}				
			}
			printf("YES\n");
			return 0;
		}
	}
	else{
		if((t-g)%k!=0) {
			printf("NO");
			return 0;
		}
		else{
			int i = g;
			while(i!=t){
				i = i+k;
				if ((a[i]!='.')&&(a[i]!='T')){
					printf("NO");
					return 0;
				}				
			}
			printf("YES\n");
			return 0;
		}

	}
	return 0;
}