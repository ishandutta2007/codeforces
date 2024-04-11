#include<bits/stdc++.h>
using namespace std;
int T,a,b;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		if((abs(a)&1)!=(abs(b)&1)){puts("-1");continue;}
		if(!a&&!b){puts("0");continue;}
		if(a+b==0){puts("1");continue;}
		if(a==b){puts("1");continue;}
		puts("2");
	}
	return 0;
}