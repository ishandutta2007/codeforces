#include <bits/stdc++.h>
using namespace std;

int n,d,h;

int main() {
	scanf("%d%d%d",&n,&d,&h);
    if (h*2<d) return printf("-1\n"), 0;
    if (h==d && n-1>d) {
    	if (d==1) return printf("-1\n"), 0;
		int on = 2;
		for (int i=0;i<h;i++) {
			printf("%d %d\n",on-1,on);
			on+=1;
		}
		while (on<=n) {
			printf("%d %d\n",2,on++);
		}
		return 0;
    }
    int on = 2;
    for (int i=0;i<h;i++) {
		printf("%d %d\n",on-1,on);
		on+=1;
    }
    if (h==d) return 0;
    int need = d-h;
    printf("1 %d\n",on++);
    for (int i=0;i<need-1;i++) {
		printf("%d %d\n",on-1,on);
		on+=1;
    }
    while (on<=n) printf("1 %d\n",on++);

	return 0;
}