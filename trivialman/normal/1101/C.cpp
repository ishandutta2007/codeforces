#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e5+5;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct dat{
	int l,r,id,gp;
	void in() {scanf("%d%d",&l,&r);}
}a[N];
int T,n;

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n) a[i].in(), a[i].id=i;
		sort(a+1,a+n+1,[](dat x,dat y){return x.l<y.l;});
		int mr = 0, p = 0;
		rep(i,1,n){
			if(i>1 && a[i].l>mr){
				p = i-1; break;
			}
			mr = max(mr, a[i].r);
		}
		if(!p){
			printf("-1\n");
		}else{
			p = a[p].l;
			sort(a+1,a+n+1,[](dat x,dat y){return x.id<y.id;});
			rep(i,1,n) printf("%d%c",a[i].l<=p?1:2,i==n?'\n':' ');
		}
	}
	return 0;
}