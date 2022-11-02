#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>
#include <stack>
#include <set>
#include <map>

char s[1000];
int n,k,a,b,sum=0,o[1000];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	memset(o,0,sizeof(o));
	scanf("%d%d%d\n",&k,&a,&b);
	for (int i=0;i<k;i++){
		o[i]=b;	
		sum+=b;
	}
	gets(s);
	n=strlen(s);
	bool ok=true;
	if (sum<n){
		puts("No solution");
		return 0;
	}
	while (sum>n){
		ok=false;
		for (int i=0;i<k;i++)
			if (o[i]>a){
				o[i]--;
				sum--;
				ok=true;
				break;
			}
		if (!ok)break;
	}
	if (!ok)      
		puts("No solution");
	else{
		int x=0;
		for (int i=0;i<k;i++){
			for (int j=0;j<o[i];j++)
				putchar(s[x++]);
			putchar('\n');
		}
	}
}