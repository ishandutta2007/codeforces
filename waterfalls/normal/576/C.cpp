#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MP make_pair
#define A first
#define B second

int n;
pair<pair<int,int>,int> X[1000013];

#define SQRT 1000

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
	if (a.A.A/SQRT!=b.A.A/SQRT) return a.A.A/SQRT<b.A.A/SQRT;
	return (a.A.A/SQRT)%2==0 ? a.A.B<b.A.B : a.A.B>b.A.B;
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&X[i].A.A,&X[i].A.B), X[i].B = i;
	sort(X,X+n,comp);
	for (int i=0;i<n;i++) printf("%d ",X[i].B+1);
	printf("\n");

	return 0;
}