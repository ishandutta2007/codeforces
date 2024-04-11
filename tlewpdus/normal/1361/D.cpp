#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,int> pdi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n, k;
pll arr[500100];
const pll Z = pll(0,0);
vector<double> w[500100];
int key[500100];

ll ccw(pll a, pll b, pll c) {
	return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
}
ll dis(pll a) {
	return (a.first*a.first+a.second*a.second);
}

int main(){
	scanf("%d%d",&n,&k);
	int zi = 0;
	for (int i=0;i<n;i++) {
		int a, b;
		scanf("%d%d",&a,&b);
		arr[i] = {a,b};
		if (a==0&&b==0) zi = i;
	}
	swap(arr[0],arr[zi]);
	sort(arr+1,arr+n,[](pll &A, pll &B) {
		if ((A>Z)!=(B>Z)) return (A>Z);
		if (ccw(Z,A,B)!=0) return ccw(Z,A,B)>0;
		return dis(A)<dis(B);
	});
	int p = 0, ti = 0;
	for (int i=1;i<n;i++) {
		if (i==n-1);
		else {
			pll A = arr[i];
			pll B = arr[i+1];
			if ((A>Z)==(B>Z) && ccw(Z,A,B) == 0) continue;
		}
		ll pp = k-1;
		//w[ti].push_back(0);
		int j;
		for (j=i;j>=p;j--) {
			if (pp<0) break;
			w[ti].push_back(pp*sqrt(dis(arr[j])));
			pp -= 2;
		}
		double psum = 0;
		for (int k=p;k<=j;k++) {
			w[ti].push_back(pp*sqrt(dis(arr[k]))-2*psum);
			psum += sqrt(dis(arr[k]));
		}
		ti++;
		p = i+1;
	}
//	for (int i=0;i<ti;i++) {
//		printf("%d \n",i);
//		for (double &v : w[i]) printf("%f ",v); puts("");
//	}
	priority_queue<pdi> pq;
	for (int i=0;i<ti;i++) {
		pq.push({w[i][0],i});
	}
	double ans = 0;
	for (int j=0;j<k;j++) {
		pdi tmp = pq.top(); pq.pop();
		ans += tmp.first;
		key[tmp.second]++;
		if (key[tmp.second]<w[tmp.second].size()) {
			pq.push({w[tmp.second][key[tmp.second]],tmp.second});
		}
	}
	printf("%.20f\n",ans);

	return 0;
}