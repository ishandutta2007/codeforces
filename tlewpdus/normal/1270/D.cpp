#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MOD = 1e9+7;
const int INT = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, k;
vector<int> vec;

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<k+1;i++) {
		printf("? ");
		for (int j=0;j<k+1;j++) {
			if (j==i) continue;
			printf("%d ",j+1);
		}
		printf("\n");
		fflush(stdout);
		int a;
		scanf("%*d%d",&a);
		vec.push_back(a);
	}
	sort(vec.begin(),vec.end());
	for (int i=0;i<vec.size();i++) {
		if (i+1==vec.size()||vec[i]!=vec[i+1]) {
			printf("! %d\n",(int)vec.size()-1-i);
			fflush(stdout);
			return 0;
		}
	}

	return 0;
}