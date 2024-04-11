#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007; //998244353

int N;
char str[300100];

int main() {
	int t;

	scanf("%d",&t);
	while(t--){
		scanf("%d",&N);
		scanf(" %s",str);
		int mang = 0, dir = 0, ans = 0;
		for (int i=0;i<N;i++) {
			if (str[i]=='-'||str[(i+1)%N]=='-') ans++;
			if (str[i]=='>') {
				if (dir==-1) mang = 1;
				dir = 1;
			}
			else if (str[i]=='<') {
				if (dir==1) mang = 1;
				dir = -1;
			}
		}
		if (mang) printf("%d\n",ans);
		else printf("%d\n",N);
	}

	return 0;
}