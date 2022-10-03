#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second

const int DEF=3849234;
int main() {
	int n; scanf("%d",&n);
	int L=DEF,R=DEF;
	for(;n--;) {
		int c,d; scanf("%d%d",&c,&d);
		if(d==2) {
			if(R==DEF || R>1899) R=1899;
		} else
		if(d==1) {
			if(L==DEF || L<1900) L=1900;
		} else
		assert(0);
		if(L!=DEF) L+=c;
		if(R!=DEF) R+=c;
	}

	if(L!=DEF && R!=DEF && L>R) {
		cout<<"Impossible\n";
	} else if(R==DEF) {
		cout<<"Infinity\n";
	} else {
		cout<<R<<endl;
	}
}