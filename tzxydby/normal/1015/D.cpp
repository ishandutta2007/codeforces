#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n, k, s;
	cin >> n >> k >> s;
	if(s<k || s>(n-1)*k){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	int st=1;
	while(k--){
		int rm=min(s-k, n-1);
		s-=rm;
		if(st+rm<=n) st+=rm;
		else st-=rm;
		cout << st << " ";

	}
	cout << endl;
}