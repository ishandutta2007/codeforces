#include <bits/stdc++.h>
using namespace std;
#define ll long long

const long long inf=(1ll<<32)-1;
int n,cnt[105];
stack<int> stk;
void no() {
	printf("OVERFLOW!!!\n");
	exit(0);
}
int main() {
	scanf("%d",&n);
	vector<ll> ans;
	ll val=0;
	for(int i=1;i<=n;i++) {
		char op[5];
		scanf("%s",op);
		if(op[0]=='a') {
			int tot=0;
			ll pr=1;
			for(int j=2;j<=100;j++) for(int rep=0;rep<cnt[j];rep++) {
				pr*=j;
				if(pr>inf) {
					no(); break;
				}
			}
			val+=pr;
			if(val>inf) no();
		} else if(op[0]=='e') {
			assert(!stk.empty()); cnt[stk.top()]--; stk.pop();
		} else {
			int x;
			scanf("%d",&x);
			cnt[x]++;
			stk.push(x);
		}
	}
	printf("%lld",val);
	return 0;
}