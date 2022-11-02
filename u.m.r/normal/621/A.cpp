#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int p = 1e9 + 10, q = 1e9 + 10, r = 1e9 + 10;
	int l = 0;//r = 0;
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		int x; 
		scanf("%d", &x);
		if (x & 1 == 1){
			l++;
			if (x < p){
				p = x;
				q = p;
			}
			else{
				if (x < q)
					q = x;
			}
		}
		else{
		//	r++;
			if (x < r)
				r = x;
		}
		ans += x;
	}
	if (ans % 2 == 0)
		cout<<ans<<endl;
	else
		cout<<ans - p<<endl;
	return 0;
}