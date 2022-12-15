#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

int main(){
	set<int> wtf;
	for(int i=0;i<4;i++){
		int x; scanf("%d",&x);
		wtf.insert(x);
	}
	printf("%d\n",4-wtf.size());
	return 0;
}