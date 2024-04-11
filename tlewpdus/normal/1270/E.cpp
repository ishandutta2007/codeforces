#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MOD = 1e9+7;
const int INT = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
pii arr[1010];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int a, b;
		scanf("%d%d",&a,&b);
		arr[i] = pii(a+1000000,b+1000000);
	}
	vector<int> res;
	for (int b=1;;b*=2) {
		for (int i=0;i<n;i++){
			if (arr[i].first%2==arr[i].second%2) res.push_back(i);
		}
		if (res.size()>0&&res.size()<n) {
			printf("%d\n",res.size());
			for (int &v : res) printf("%d ",v+1);
			break;
		}
		res.clear();
		for (int i=0;i<n;i++) {
			if (arr[i].first%2) res.push_back(i);
		}
		if (res.size()>0&&res.size()<n) {
			printf("%d\n",res.size());
			for (int &v : res) printf("%d ",v+1);
			break;
		}
		res.clear();
		for (int i=0;i<n;i++) {
			arr[i].first/=2;
			arr[i].second/=2;
		}
	}

	return 0;
}