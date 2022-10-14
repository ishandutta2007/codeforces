#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
	scanf("%i%i",&a,&b);
	if(a<b)printf("-1");
	else printf("%.12lf",(a+b)/(2.0*((a+b)/(2*b))));
}