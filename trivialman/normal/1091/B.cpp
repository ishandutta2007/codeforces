#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const int MOD = 998244353;
const int N = 1010;

struct dat{
	int x,y;
}a[N],b[N];
int n;

bool cmp(dat x, dat y){return x.x<y.x||x.x==y.x&&x.y<y.y;}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	rep(i,1,n)cin>>a[i].x>>a[i].y;
	rep(i,1,n)cin>>b[i].x>>b[i].y;
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	cout<<a[1].x+b[n].x<<" "<<a[1].y+b[n].y<<endl; 
	return 0;
}