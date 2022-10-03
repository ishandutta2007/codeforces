// ayy
// ' lamo
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;
const int P=1e9+7;





const int N=1<<19;
int n;
char s[N];
int ct[256];






int32_t main() {
	scanf("%d%s",&n,s); s[n]=0;
	for(int i=0;i<n;i++) ++ct[int(s[i])];
	vector<char> odds;
	for(int i=0;i<256;i++) if(ct[i]&1) odds.pb(char(i));

	if(!odds.size()) {
		int ii=0;
		for(int i=0;i<256;i++) for(;ct[i];) {
			ct[i]-=2;
			s[ii]=char(i);
			s[n-1-ii]=s[ii];
			++ii;
		}
		printf("1\n%s\n",s);
		return 0;
	}

	for(int k=(int)odds.size();k<=n;k++) {
		if(n%k) continue;
		int w=n/k;
		if((w&1)==0) continue;

		for(int i=0;i<256;i++) {
			for(;ct[i]>=2 && (int)odds.size() < k;) {
				odds.pb(char(i));
				odds.pb(char(i));
				ct[i]-=2;
			}
		}

		printf("%d\n",k);
		s[w]=0;
		for(int its=0;its<k;its++) {
			s[w/2]=odds.back(); odds.pop_back();
			int ii=0;
			for(int i=0;i<256;i++) {
				for(;ct[i]>=2 && ii<w/2;) {
					ct[i]-=2;
					s[ii]=char(i);
					s[w-1-ii]=s[ii];
					++ii;
				}
			}
			printf("%s%c",s," \n"[its==k-1]);
		}
		return 0;
	}
	assert(0);
}