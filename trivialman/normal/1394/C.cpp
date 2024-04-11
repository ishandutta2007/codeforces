#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 200003;
const int INF = 1e9;
const int N = 3e5+5;
const double PI = acos(-1);
//mt19937 rng(time(0));

int n, x, y;
char tmp[N*4];

struct Range{
	int mi = INF, ma = -INF;
	void update(int x){
		mi = min(mi, x);
		ma = max(ma, x);
	}
}a, b, ab;

bool check(int k){
	if (2*k < ab.ma-ab.mi) return false;
	x = a.mi+k, y = b.mi+k;
	x = min(x, y - ab.ma + k);
	y = min(y, x + ab.mi + k);
	return x+k>=a.ma && y+k>=b.ma;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",tmp+1);
		int len = strlen(tmp+1);
		x = y = 0;
		rep(j,1,len) (tmp[j]=='B'?x:y)++;
		a.update(x), b.update(y), ab.update(y-x);
	}
	
	int l = 0, r = 1e6, ans;
	while(l<=r){
		int mid=l+r>>1;
		if (check(mid)) r = mid-1, ans = mid;
		else l = mid+1;
	}
	
	x = a.mi+ans, y = b.mi+ans;
	x = min(x, y - ab.ma + ans);
	y = min(y, x + ab.mi + ans);
	rep(i,1,x) tmp[i] = 'B';
	rep(i,x+1,x+y) tmp[i] = 'N';
	tmp[x+y+1] = 0;
	printf("%d\n%s\n",ans,tmp+1);
	return 0;
}