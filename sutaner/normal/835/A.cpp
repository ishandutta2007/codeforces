#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	/*freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);*/
	int a, b, c, d, e;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	int res1 = a * b + 2 * d;
	int res2 = a * c + 2 * e;
	if (res1 < res2){printf("First");}
	else if (res1 > res2){printf("Second");}
	else {printf("Friendship");}
	return 0;
}