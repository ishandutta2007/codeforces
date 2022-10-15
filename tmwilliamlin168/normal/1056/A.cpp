#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, r, ai;
	cin >> n;
	bool a[100], b[100];
	memset(a, 1, 100);
	while(n--) {
		cin >> r;
		memset(b, 0, 100);
		for(int i=0; i<r; ++i)
			cin >> ai, b[ai-1]=1;
		for(int i=0; i<100; ++i)
			if(!b[i])
				a[i]=0;
	}
	for(int i=0; i<100; ++i)
		if(a[i])
			cout << i+1 << " ";
}