#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const int N = 1e7+5, N1 = 250010;

struct dat{ int pos; LL val; }s[N];
int n,m,q,x,y,l[N],r[N];
vector<LL> blka[N1], blkc[N1];
LL a[N],c[N],dp[N],id,mul,cnt=0,top,t;

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&x);
		rep(j,1,x)scanf("%d", &y),blka[i].push_back(y);
		rep(j,1,x)scanf("%d", &y),blkc[i].push_back(y);
	} 
	scanf("%d",&q);
	rep(i,1,q){
		scanf("%d%d",&id,&mul);
		rep(j,1,blka[id].size())a[++cnt]=blka[id][j-1],c[cnt]=blkc[id][j-1]*mul;
	}
	top = 0;
	rep(i,1,m){
		while(top && s[top].pos > i-a[i]) --top;
		l[i] = (i==1||a[i]==1) ? i : s[++top].val;
		s[++top] = {i,l[i]};
	}
	top = 0;
	for(int i=m;i;--i){
		while(top && s[top].pos < i+a[i]) --top;
		r[i] = (i==m||a[i]==1) ? i : s[++top].val;
		s[++top] = {i,r[i]};
	}
	top = 0;
	rep(i,1,m){
		while(top&&s[top].pos<i)--top;
		dat x = {r[i], dp[i-1]+c[i]};
		while(top && s[top].val>x.val && s[top].pos==x.pos)--top;
		if(!top||x.val<s[top].val)s[++top] = x;
		dp[i] = min(dp[l[i]-1] + c[i], s[top].val);
	}
	cout<<dp[m]<<endl;
}