#include<bits/stdc++.h>
using namespace std;
int pos[4000];
int main(){
	int t;
	scanf("%d",&t);
	int n;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) pos[i]=i;
		int j[4];
		for(int i=0;i<4;i++){
			printf("? ");
			for(int k=0;k<4;k++) if(k!=i) printf("%d ",pos[n-k]);
			printf("\n");
			fflush(stdout);
			scanf("%d",&j[i]);
		}
		int maxx=max(max(j[0],j[1]),max(j[2],j[3]));
		int num=(n%2>0) ? 1 : 2;
		int tot=0;
		for(int i=3;i>=0;i--){
			if((j[i]==maxx)&&num){
				num--;
			}
			else{
			    pos[n-3+tot]=pos[n-i];
				tot++;
			}
		}
		if(n%2) n-=1;
		else n-=2;
		for(;n>=4;n-=2){
			for(int i=0;i<4;i++){
			printf("? ");
			for(int k=0;k<4;k++) if(k!=i) printf("%d ",pos[n-k]);
			printf("\n");
			fflush(stdout);
			scanf("%d",&j[i]);
		}
		maxx=max(max(j[0],j[1]),max(j[2],j[3]));
		num=2;
		tot=0;
		for(int i=3;i>=0;i--){
			if((j[i]==maxx)&&num){
				num--;
			}
			else{
			    pos[n-3+tot]=pos[n-i];
				tot++;
			}
		}
		}
		printf("! %d %d\n",pos[1],pos[2]);
		fflush(stdout);
	}
	return 0;
}