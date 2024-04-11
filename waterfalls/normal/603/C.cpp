#include <bits/stdc++.h>
using namespace std;

int baseodd[] = {0,1,0,1,2};
int baseeven[] = {0,1,2};
int get(int sz) {
	if (sz<=4) return baseodd[sz];
	if (sz%2==1) return 0;
	return (get(sz/2)==1) ? 2 : 1;
}
int nimber(int sz, int k) {
	if (k==0) {
		if (sz<=2) return baseeven[sz];
		return (sz+1)%2;
	} else return get(sz);
}

int N,k;

int main() {
	scanf("%d%d",&N,&k);
	k%=2;
	int res = 0;
	for (int i=0;i<N;i++) {
		int a;
		scanf("%d",&a);
		res^=nimber(a,k);
	}
	printf("%s\n",(res==0) ? "Nicky" : "Kevin");

	return 0;
}