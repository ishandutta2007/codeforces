#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e6+5;
const LL INF = 1e16;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,cnt[N],ans,a[N];
void insert(int x,int y){
	if (cnt[x|y]==2)return;
	if (x==0){
		cnt[y]++;
		return;
	}
	insert(x&x-1,y|x&-x);
	insert(x&x-1,y);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	rrep(i,n,1){
		if (i+2<=n){
			int now=0;
			rrep(j,20,0) if (!(a[i]>>j&1)&&cnt[now|1<<j]==2)now|=1<<j;
			ans=max(ans,now|a[i]);
		}
		insert(a[i],0);
	}
	printf("%d\n",ans);
	return 0;
}