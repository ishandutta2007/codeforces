#include <stdio.h>
#include <string.h>
#define M 250050
typedef unsigned long long LL;
 
int a[M], b[M];
 
int main(){
	int n;
	while(~scanf("%d", &n)){
		int temp, i, j;
		int flag = -1, la, lb;
		la = lb = 0;
		LL sum1, sum2;
		sum1 = sum2 = 0;
		for(i = 0; i < n; i ++){
			scanf("%d", &temp);
			if(temp > 0){
				sum1 +=temp;
				flag = 1;
				a[la++] = temp;
			}
			else {
				temp = -temp;
				sum2 += temp;
				flag = 2;
				b[lb++] = temp;
			}
		}
		if(sum1 > sum2){
			printf("first\n");
		}
		else if(sum1 < sum2){
			printf("second\n");
		}
		else{
			i = 0; j = 0;
			int ok = 0;
			while(i<la&&j<lb){
				if(a[i] == b[j]){
					++i; ++j;
				}
				else{
					if(a[i] > b[j]) puts("first");
					else puts("second");
					return 0;
				}
			}
			if(la >lb){
                printf("first\n"); return 0;
			}
			if(la < lb){
                printf("second\n");
                return 0;
			}
			if(flag == 1) printf("first\n");
			else printf("second\n");
        }
	}
	return 0;
}