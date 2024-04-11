#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 200010;

struct dat{
	int x,y;
}a[N];
int n, tr[N];
LL ans=0;

void add(int x,int val){
	for(;x<=n;x+=x&-x)tr[x]+=val;
}
int sum(int x){
	int res=0;
	for(;x;x-=x&-x)res+=tr[x];
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	
	sort(a+1,a+n+1,[](dat x,dat y){return x.x<y.x;});
	int newx=a[1].x,tmp;a[1].x=1;
	rep(i,2,n){
		tmp = a[i].x, a[i].x = (a[i].x==newx?a[i-1].x:a[i-1].x+1), newx = tmp;
	}
	
	sort(a+1,a+n+1,[](dat x,dat y){return x.y<y.y;});
	int newy=a[1].y;a[1].y=1;
	rep(i,2,n){
		tmp = a[i].y, a[i].y = (a[i].y==newy?a[i-1].y:a[i-1].y+1), newy = tmp;
	}
	
	sort(a+1,a+n+1,[](dat x,dat y){return x.y>y.y||x.y==y.y&&x.x<y.x;});
	//rep(i,1,n)cout<<a[i].x<<" "<<a[i].y<<endl;
	
	int i,j;
	for(i=1;i<=n;i=j){
		for(j=i;j<=n&&a[j].y==a[i].y;++j)
			if(sum(a[j].x)==sum(a[j].x-1)){
				add(a[j].x,1);
			}
		int sz = sum(n);
		ans += 1ll * sz * (sz+1) / 2;
		rep(k,i,j-2){
			int sz = sum(a[k+1].x)-sum(a[k].x)-1;
			ans -= 1ll * sz * (sz+1) /2;
		}
		sz = sum(a[i].x-1);
		ans -= 1ll * sz * (sz+1) /2;
		sz = sum(n) - sum(a[j-1].x);
		ans -= 1ll * sz * (sz+1) /2;
	}
	printf("%lld\n",ans);
	return 0;
}