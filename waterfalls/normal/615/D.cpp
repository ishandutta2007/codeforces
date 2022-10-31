#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
int add(int a, int b, int mo=MOD) { return a+b-(a+b>=mo)*mo; }
int sub(int a, int b, int mo=MOD) { return a-b+(a-b<0)*mo; }
int mult(int a, int b, int mo=MOD) { return ((ll) a*b)%mo; }
int pow(int a, int b, int mo=MOD) {
	int ans = 1;
	for (int i=0;i<30;i++) {
		if (b&(1<<i)) ans = mult(ans,a,mo);
		a = mult(a,a,mo);
	}
	return ans;
}
int inv(int a, int mo=MOD) { return pow(a,mo-2,mo); }

int n;
map<int,int> has;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int p;
		scanf("%d",&p);
		has[p]+=1;
	}
	bool sq = 1;
	for (auto it: has) if (it.second%2==1) sq = 0;
	if (sq) {
		int cur = 1;
		int num = 1;
		for (auto it: has) {
			cur = mult(cur,pow(it.first,it.second/2));
			num = mult(num,it.second+1,MOD-1);
		}
		printf("%d\n",pow(cur,num));
	} else {
		int cur = 1;
		int num = 1;
		bool found = 0;
		for (auto it: has) {
			cur = mult(cur,pow(it.first,it.second));
			if (!found && it.second%2==1) {
				it.second = it.second/2;
				found = 1;
			}
			num = mult(num,it.second+1,MOD-1);
		}
		printf("%d\n",pow(cur,num));
	}

	return 0;
}