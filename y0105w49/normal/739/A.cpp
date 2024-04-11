#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
const int inf=1e9+99;

const int N=1.1e5;
pair<int,int> P[N];
int n,m;

int main() {
	scanf("%d%d",&n,&m);
	int L,R;
	int be=1e9;
	for(int i=0;i<m;i++) {
		scanf("%d%d",&L,&R);
		P[i]={L,R};
		be=min(be,R-L);
	}

	printf("%d\n",be+1);
	for(int i=0;i<n;i++) printf("%d%c",i%(be+1)," \n"[i==n-1]);
}