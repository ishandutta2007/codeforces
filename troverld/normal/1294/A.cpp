#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,c,s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&a,&b,&c,&n),s=a+b+c+n;
		if(s%3){puts("NO");continue;}
		s/=3;
		if(a>s||b>s||c>s){puts("NO");continue;}
		puts("YES");
	}
	return 0;
}