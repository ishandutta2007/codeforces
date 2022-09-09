#include<stdio.h>
#include<algorithm>

using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	printf("%d\n",max(max(a-c,c-a),max(b-d,d-b)));
	return 0;
}