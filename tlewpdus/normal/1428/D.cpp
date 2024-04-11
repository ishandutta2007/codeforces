#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007; //998244353

void pung() {
	puts("-1");
	exit(0);
}

int N;
int A[100100];

int main() {
	scanf("%d",&N);
	for (int i=0;i<N;i++) scanf("%d",&A[i]);
	vector<int> ex3;
	for (int i=0;i<N;i++) {
		if (A[i]==3) {ex3.push_back(i);}
	}
	int curi = 0;
	vector<pii> ans;
	if (!ex3.empty()) {
		int ex2 = -1, ex1 = -1;
		for (int i=ex3.back();i<N;i++) {
			if (A[i]==2) ex2 = i;
			if (A[i]==1&&ex1==-1) ex1 = i;
		}
		if (ex2==-1&&ex1==-1) {
			pung();
		}
		if (ex2==-1) {
			ex3.push_back(ex1);
			for (int i=0;i+1<ex3.size();i++) {
				ans.push_back({curi,ex3[i]});
				ans.push_back({curi,ex3[i+1]});
				curi++;
			}
			ans.push_back({curi,ex3.back()});
			curi++;
			A[ex1] = 0;
		}
		else {
			ex3.push_back(ex2);
			for (int i=0;i+1<ex3.size();i++) {
				ans.push_back({curi,ex3[i]});
				ans.push_back({curi,ex3[i+1]});
				curi++;
			}
		}
	}
	vector<int> st;
	for (int i=0;i<N;i++) {
		if (A[i]==2) {
			st.push_back(i);
		}
		else if (A[i]==1) {
			if (st.empty()) {
				ans.push_back({curi,i});
				curi++;
			}
			else {
				ans.push_back({curi,st.back()});
				ans.push_back({curi,i});
				curi++;
				st.pop_back();
			}
		}
	}
	if (!st.empty()) pung();
	printf("%d\n",ans.size());
	for (pii &v : ans) {
		printf("%d %d\n",v.first+1,v.second+1);
	}

	return 0;
}