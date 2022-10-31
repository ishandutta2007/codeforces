#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;
typedef pair<int,int> ip;
typedef tuple<int,int,int> itp;

map<int,int> tr[201];
int n,k;
int a[200],b[200];

int main() {
	long long val;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) {
		scanf("%lld",&val);
		while(val%2==0) val/=2,b[i]++;
		while(val%5==0) val/=5,a[i]++;
	}
	queue<itp> que;
	tr[1][a[0]]=b[0];
	que.push(make_tuple(1,a[0],b[0]));
	for(int i=1;i<n;i++) {
		while(!que.empty()) {
			int s,aa,bb;
			tie(s,aa,bb)=que.front();que.pop();
			s++; aa+=a[i]; bb+=b[i];
			
			if(tr[s].count(aa)==0||tr[s][aa]<bb) tr[s][aa]=bb;
		}
		if(tr[1].count(a[i])==0||tr[1][a[i]]<b[i]) tr[1][a[i]]=b[i];
		if(i==n-1) break;
		for(int j=0;j<k;j++) {
			for(auto &it:tr[j]) que.push(make_tuple(j,it.first,it.second));
		}
	}

	int mx=0;
	for(auto &it:tr[k]) {
		mx=max(mx,min(it.first,it.second));
	}
	printf("%d\n",mx);

	return 0;
}