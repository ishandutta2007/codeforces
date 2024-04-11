#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	puts(!a&&b&&d||!c&&d||a*c*e<b*d*f?"Ron":"Hermione");
}