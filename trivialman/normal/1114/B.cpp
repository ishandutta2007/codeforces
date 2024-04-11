#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 200010;

struct dat{
	int x,id,num;
}a[N];

int n,m,k;

bool cmp1(dat x, dat y){return x.x>y.x;}
bool cmp2(dat x, dat y){return x.id<y.id;}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+1+n,cmp1);
	rep(i,1,n) a[i].num = i;
	sort(a+1,a+1+n,cmp2);
	LL ans=0,cnt=0;
	vector<int> p;
	rep(i,1,n)if(a[i].num<=k*m){
		ans += 1ll * a[i].x;
		++cnt;
		if(cnt>=m){
			cnt=0;
			p.push_back(i);
		}
	}
	printf("%lld\n",ans);
	rep(i,0,p.size()-2)printf("%d ",p[i]);
	return 0;
}