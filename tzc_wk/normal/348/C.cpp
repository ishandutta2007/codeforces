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
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=1e5;
const int SQRT=316;
int n,m,qu;ll a[MAXN+5];
vector<int> s[MAXN+5];
int bg[SQRT+5],bgnum=0,same[MAXN+5][SQRT+5];
bitset<MAXN+5> vis[SQRT+5];
ll anss[MAXN+5],add[MAXN+5];
int main(){
	scanf("%d%d%d",&n,&m,&qu);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++){
		int len;scanf("%d",&len);
		for(int j=1;j<=len;j++){
			int x;scanf("%d",&x);s[i].pb(x);
			anss[i]+=a[x];
		}
		if(len>=SQRT){
			bg[++bgnum]=i;
			for(int j=0;j<s[i].size();j++){
				vis[bgnum][s[i][j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<s[i].size();j++)
			for(int k=1;k<=bgnum;k++)
				if(vis[k][s[i][j]]) same[i][k]++;
	while(qu--){
		static char opt[3];scanf("%s",opt+1);
		if(opt[1]=='?'){
			int x;scanf("%d",&x);
			ll ans=0;
			if(s[x].size()<SQRT){
				for(int j=0;j<s[x].size();j++) ans+=a[s[x][j]];
				for(int j=1;j<=bgnum;j++) ans+=1ll*add[bg[j]]*same[x][j];
				printf("%lld\n",ans);
			} else printf("%lld\n",anss[x]);
		} else {
			int x,y;scanf("%d%d",&x,&y);
			if(s[x].size()<SQRT){
				for(int j=0;j<s[x].size();j++) a[s[x][j]]+=y;
				for(int j=1;j<=bgnum;j++) anss[bg[j]]+=1ll*y*same[x][j];
			} else {
				for(int j=1;j<=bgnum;j++) anss[bg[j]]+=1ll*y*same[x][j];
				add[x]+=y;
			}
		}
	}
	return 0;
}