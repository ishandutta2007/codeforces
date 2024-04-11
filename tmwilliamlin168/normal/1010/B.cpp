#include <bits/stdc++.h>
using namespace std;

int m, n, p[30], x, a;

int qry(int y) {
	cout << y << endl;
	int ans;
	cin >> ans;
	if(!ans)
		exit(0);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	for(int i=0; i<n; ++i)
		p[i]=qry(1);
	for(int i=29; i>=0; --i) {
		if(x+(1<<i)>m)
			continue;
		if(qry(x+(1<<i))*p[a++%n]==1)
			x+=1<<i;
	}
}