#include <stdio.h>

int main(){
	int n; 
	scanf("%d",&n);
	int pv=-1;
	int j=0;
	int tc=0;
	for (int i=0;i<n;i++) {
	    int p;
	    scanf("%d",&p);
		if (p!=pv) { 
			pv=p;
			if (j) {
				if (tc) { 
				    if (j!=tc){
				        printf("NO");
				        return 0;  
				    }  
    			}
    			tc=j;
			}
			j=0; 
		}
		j++; 
	}
	if ((tc) && (j) && j!=tc) {printf("NO"); return 0;}
	else {
		printf("YES"); 
		return 0;
	}
}