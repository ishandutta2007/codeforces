#include<bits/stdc++.h>
using namespace std;
int n,l=1,r=1e9,mi,tp;
char res[10];
int main(){
    scanf("%d",&n);
    puts("1 0"),fflush(stdout);
    scanf("%s",res);
    if(res[0]=='b')tp=1;
    for(int i=1;i<n;i++){
		printf("1 %d\n",mi=l+r>>1);
		fflush(stdout);
		scanf("%s",res);
		if((res[0]=='w')^tp)l=mi+1;
		else r=mi-1;
    }
    printf("0 %d 2 %d",l,r);
}