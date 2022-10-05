#include<bits/stdc++.h>
using namespace std;
int p[11000];
bool a[11000];
int num;
int main(){
	int t,n;
	scanf("%d",&t);
	for(int jj=1;jj<=t;jj++){
		scanf("%d",&n);
		num=0;
		for(int i=1;i<=n;i++) a[i]=false;
		for(;;){
			if(num==n) break;
			int j;
			for(j=1;;j++){
				if(!a[j]) break;
			}
			int k;
			printf("? %d\n",j);
			fflush(stdout);
			scanf("%d",&k);
			int w=k,w2;
			for(;;){
				printf("? %d\n",j);
				fflush(stdout);
				scanf("%d",&w2);
				p[w]=w2;
				a[w]=true;
				num++;
				if(w2==k) break;
				w=w2;
			}
		}
		printf("!");
		for(int i=1;i<=n;i++) printf(" %d",p[i]);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}