#include <bits/stdc++.h>
using namespace std;

char ch, a, b, c, d;
int n(char c){
	if(c=='T') return 10;
	else if(c=='J') return 11;
	else if(c=='Q') return 12;
	else if(c=='K') return 13;
	else if(c=='A') return 14;
	else return c-'0';
}

int main(){
	ch = getchar(); getchar();
	scanf("%c%c %c%c",&a,&b,&c,&d);
	if(b==d){
		printf("%s\n",(n(a)>n(c))?"YES":"NO");
	}
	else if(b==ch) printf("YES\n");
	else printf("NO\n");
	return 0;
}