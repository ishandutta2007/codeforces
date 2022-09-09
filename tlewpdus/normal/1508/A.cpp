#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353; //1000000007

int N;
char S[3][200100];
string ans;

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		for (int i=0;i<3;i++) scanf(" %s",S[i]);
		int Z[3] = {0,0,0};
		for (int i=0;i<3;i++) {
			for (int j=0;j<2*N;j++) Z[i] += (S[i][j]=='0');
		}
		bool done = false;
		for (int i=0;i<3;i++) {
			for (int j=i+1;j<3;j++) {
				int mz = min(Z[i],Z[j]);
				int mo = min(2*N-Z[i],2*N-Z[j]);
				if (mz<N&&mo<N) continue;
				char t = (mz>=N?'0':'1');
				vector<int> l1, l2;
				for (int k=0;k<2*N;k++) {
					if (l1.size()<N&&S[i][k]==t) l1.push_back(k);
					if (l2.size()<N&&S[j][k]==t) l2.push_back(k);
				}
				ans.clear();
				assert(l1.size()==N&&l2.size()==N);
				for (int k=0;k<=N;k++) {
					int cur = (k==N?2*N:l1[k]);
					int pst = (k==0?0:l1[k-1]+1);
					for (int l=pst;l<cur;l++) ans.push_back(S[i][l]);
					cur = (k==N?2*N:l2[k]);
					pst = (k==0?0:l2[k-1]+1);
					for (int l=pst;l<cur;l++) ans.push_back(S[j][l]);
					if (k!=N) ans.push_back(t);
				}
				printf("%s\n",ans.c_str());
				done = true;
				break;
			}
			if (done) break;
		}
	}

	return 0;
}