#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int INF = 1e9;
const int N = 3e5+5;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct dat{
	LL k,b;
}S[N];
int m, t, r;
LL n, k, b, x, y;

double getk(dat a,dat b){return 1.0*(b.b-a.b)/(b.k-a.k);}
LL calc(dat a){return (a.k-1) * k + b + a.b;}

int main(){
	//freopen("test.in","r",stdin);
	scanf("%lld%d",&n,&m);
	S[r = 1] = {1, 0};
	
	rep(i,1,m){
		scanf("%d",&t);
		if(t==1){
			scanf("%lld",&x);
			n += x;
			k = b = 0;
			S[r = 1] = {1,0};
		}else if(t==2){
			scanf("%lld",&x);
			dat a = {n+1,-calc({n+1,0})};
			while(r>1 && getk(S[r],a) < getk(S[r-1],S[r])) --r;
			S[++r] = a;
			n += x;
		}else{
			scanf("%lld%lld",&x,&y);
			b += x, k += y;
		}
		
		while(r>1 && calc(S[r])>=calc(S[r-1]) ) --r;
		printf("%lld %lld\n",S[r].k,calc(S[r]));
	}
	return 0;
}