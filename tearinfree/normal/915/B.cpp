#include <cstdio>
#include <algorithm>

using namespace std;

int _abs(int a) {
	return a<0 ? -a : a;
}

int main() {
	int n,k,l,r;
	scanf("%d%d%d%d",&n,&k,&l,&r);
	if(r-l+1==n) puts("0");
	else {
		if(l==1) printf("%d\n",_abs(r-k)+1);
		else if(r==n) printf("%d\n",_abs(l-k)+1);
		else {
			printf("%d\n",min( _abs(l-k)+_abs(r-l)+2, _abs(r-k)+_abs(r-l)+2));
		}
	}
}