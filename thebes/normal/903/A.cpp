#include <bits/stdc++.h>
using namespace std;

int n, x, i, flag;

int main(){
	for(scanf("%d",&n);n>0;n--){
		scanf("%d",&x);flag=0;
		for(i=0;3*i<=x;i++)
			if((x-3*i)%7==0) flag=1;
		printf("%s\n",(flag)?"YES":"NO");
	}
	return 0;
}