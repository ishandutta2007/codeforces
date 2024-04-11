#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const int inf=1e9+99;
const ld eps=1e-10;


int main() {
	int n; scanf("%d",&n);
	int p=1;
	int ans[1024];
	for(int i=0;i<n;i++) ans[i]=inf;
	for(int it=0;it<10;it++) {
		int x=0;
		vector<int> qs;
		for(;;) {
			for(int j=0;j<p;j++) qs.push_back(x++);
			x+=p;
			if(x>n) break;
		}
		for(;!qs.empty() && qs.back()>=n;) qs.pop_back();
		set<int> inq;
		for(int x:qs) inq.insert(x);
		if(!qs.size()) goto s1;
		printf("%d\n",(int)qs.size());
		for(int i=0;i<(int)qs.size();i++) printf("%d%c",qs[i]+1," \n"[i==(int)qs.size()-1]);
		fflush(stdout);
		for(int i=0;i<n;i++) {
			int z; scanf("%d",&z);
			if(!inq.count(i)) ans[i]=min(ans[i],z);
		}
		s1:;
		qs.clear();
		for(int i=0;i<n;i++) if(!inq.count(i)) qs.pb(i);
		if(!qs.size()) goto s2;
		printf("%d\n",(int)qs.size());
		for(int i=0;i<(int)qs.size();i++) printf("%d%c",qs[i]+1," \n"[i==(int)qs.size()-1]);
		fflush(stdout);
		for(int i=0;i<n;i++) {
			int z; scanf("%d",&z);
			if(inq.count(i)) ans[i]=min(ans[i],z);
		}
		s2:;
		p*=2;
	}
	printf("-1\n");
	for(int i=0;i<n;i++) printf("%d%c",ans[i]," \n"[i==n-1]);
	fflush(stdout);
}