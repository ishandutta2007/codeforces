#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
typedef long long LL;
const int P = 998244353;
const int N = 1e5+5;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Point{
	LL x,y;
	void read(){ scanf("%lld%lld",&x,&y), y -= x*x; }
	bool operator<(Point r){return x<r.x || x==r.x && y<r.y;}
}a[N],b[N],stk[N];

int n,n1,top;

bool check(Point a,Point b,Point c){
	LL x1 = b.x-a.x, x2=c.x-a.x, y1=b.y-a.y, y2=c.y-a.y;
	return x2*y1-y2*x1>0;
}

int main() {
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)a[i].read();
	
	sort(a+1,a+n+1);
	memcpy(b,a,sizeof a);
	
	b[n+1]={1<<25,1<<25};
	n1 = 0;
	rep(i,1,n) if(b[i+1].x!=b[i].x) a[++n1] = b[i];
	n = n1;
	//cout<<n<<endl;
	//rep(i,1,n) cout<<a[i].x<<" "<<a[i].y<<endl;
	rep(i,1,n){
		while(top>1 && !check(stk[top-1],stk[top],a[i])) --top;
		stk[++top] = a[i];
	}
	cout<<top-1<<endl;
}