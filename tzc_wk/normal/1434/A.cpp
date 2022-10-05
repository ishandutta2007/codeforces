#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
int a[7],n,b[100005];
int key[600005],cnt=0,hs[600005],num=0;
int dif[100005][7];
vector<pii> t[600005];
int main(){
	fz(i,1,6) cin>>a[i];cin>>n;
	fz(i,1,n) cin>>b[i];sort(a+1,a+7);reverse(a+1,a+7);
	fz(i,1,n) fz(j,1,6) key[++cnt]=b[i]-a[j],dif[i][j]=b[i]-a[j];
	sort(key+1,key+cnt+1);
	fz(i,1,cnt) if(key[i]!=key[i-1]) hs[++num]=key[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++){
			dif[i][j]=lower_bound(hs+1,hs+num+1,dif[i][j])-hs;
			t[dif[i][j]].pb(make_pair(i,j));
		}
	}
	int mx=0,ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++) mx=max(mx,dif[i][1]);
	for(int i=1;i<=num;i++){
		bool flg=1;
		for(int j=0;j<t[i-1].size();j++){
			int x=t[i-1][j].fi,y=t[i-1][j].se;
			if(y==6) flg=0;mx=max(mx,dif[x][y+1]);
		}
		if(!flg) break;
		ans=min(ans,hs[mx]-hs[i]);
	}
	printf("%d\n",ans);
	return 0;
}