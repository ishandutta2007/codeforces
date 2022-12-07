#include<cstdlib>
#include<algorithm>
#include<cstdio>
#define maxn 
using namespace std;
int gcd(int x,int y){//x>y
	if(y==0)return x;
	return gcd(y,x%y);
}
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",c/(a*b/gcd(max(a,b),min(a,b))));
	return 0;
}