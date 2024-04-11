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
const int MAXN=3e5+5;
int n,a[MAXN];
priority_queue<int,vector<int>,greater<int> > q;
ll ans=0;
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(!q.empty()&&q.top()<a[i]){
			ans+=a[i]-q.top();q.pop();q.push(a[i]);
		} q.push(a[i]);
	} printf("%lld\n",ans);
	return 0;
}