#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
const int B=15;
const int TOT=(1<<B)-1;
const int MAXN=100+5;
const ll BASE=149;
const ll MOD=1000000013;
int n,l[MAXN],r[MAXN];
map<vector<int>,int> mmp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		l[i]=x>>B;r[i]=x&TOT;
	}
	for(int i=0;i<TOT;i++){
		int mn=0x3f3f3f3f;vector<int> vv;
		for(int j=1;j<=n;j++) mn=min(mn,__builtin_popcount(r[j]^i));
		for(int j=1;j<=n;j++) vv.pb(__builtin_popcount(r[j]^i)-mn);
		mmp[vv]=i;
	}
	for(int i=0;i<TOT;i++){
		int mx=0,mn=0x3f3f3f3f;vector<int> vv;
		for(int j=1;j<=n;j++) mx=max(mx,__builtin_popcount(l[j]^i));
		for(int j=1;j<=n;j++) mn=min(mn,mx-__builtin_popcount(l[j]^i));
		for(int j=1;j<=n;j++) vv.pb(mx-__builtin_popcount(l[j]^i)-mn);
		if(mmp.find(vv)!=mmp.end()){
			printf("%d\n",(i<<B)+mmp[vv]);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}