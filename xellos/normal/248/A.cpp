// iostream is too mainstream
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
// mylittlepony
using namespace std;

int main() {
	int N;
	scanf(" %d",&N);
	int a =0, b =0, c;
	for(int i =0; i < N; i++) {
		scanf(" %d",&c);
		a +=c;
		scanf(" %d",&c);
		b +=c;}
	printf("%d\n",min(a,N-a)+min(b,N-b));
	return 0;}

// look at my code
// my code is amazing