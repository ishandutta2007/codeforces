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
int n,a[200005];
int query(int l,int r){
//	printf("%d %d\n",l,r);
	int i1=lower_bound(a+1,a+n+2,l)-a;
	int i2=lower_bound(a+1,a+n+2,r+1)-a;
	return i2-i1;
}
int dfs(int x,int y){
	int c=query(x,x+(1<<y)-1);
//	printf("%d %d\n",x,y);
	if(c==1) return 1;
	int val[32],need[32];
	for(int i=0;i<31;i++) val[i]=need[i]=0;
	int cnt=query(x,x);if(cnt) val[0]=1,need[0]=1;
	for(int i=0;i<y;i++){
		int cnt=query(x+(1<<i),x+(1<<(i+1))-1);
		if(cnt){
			val[i+1]=dfs(x+(1<<i),i);
			need[i+1]=1;
		}
	}
//	for(int i=1;i<=y;i++) cout<<val[i]<<" ";puts("");
	int ans=0,num=0;
	for(int i=1;i<=y;i++) need[i]|=need[i-1];
	for(int i=y;i;i--) if(val[i])
		ans=max(ans,val[i]+num+need[i-1]),num++;
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);a[i]=x;
	} a[n+1]=INT_MAX;
	sort(a+1,a+n+1);
	printf("%d\n",n-dfs(0,30));
	return 0;
}
/*
8
0 1 2 3 4 5 6 7

4
1 3 5 7
*/