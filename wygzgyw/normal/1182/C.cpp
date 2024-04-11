#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+5;
int n,len,lst,a,b,c,mx,tmp;
string s[maxn];
int vis[300],ans;
int cnt[maxn*10][6];
vector<int> g[maxn*10][6];
int t1[maxn][3],t2[maxn][3];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	vis['a']=1;
	vis['e']=2;
	vis['i']=3;
	vis['o']=4;
	vis['u']=5;
	for (int i=1;i<=n;i++) {
		cin>>s[i];
		len=s[i].size();
		lst=a=0;
		for (int j=0;j<len;j++) {
			if (!vis[s[i][j]]) continue;
			lst=vis[s[i][j]]; a++;
		}
		cnt[a][lst]++;
		mx=max(mx,a);
		g[a][lst].push_back(i);
	}
	a=b=0;
	for (int i=1;i<=mx;i++) {
		c=0;
		for (int j=1;j<=5;j++)
			if (cnt[i][j]) {
				b+=cnt[i][j]/2;
				c+=cnt[i][j]&1;
			}
		a+=c/2;
	}
	if (a>=b) ans=b;
	else ans=(a+b)/2;
	printf("%d\n",ans);
	a=b=0;
	for (int i=1;i<=mx;i++) {
		lst=0;
		for (int j=1;j<=5;j++)
			if (cnt[i][j]) {
				for (int k=0;k+1<g[i][j].size();k+=2) {
					if (b<ans)
						t2[++b][1]=g[i][j][k],t2[b][2]=g[i][j][k+1];
					else t1[++a][1]=g[i][j][k],t1[a][2]=g[i][j][k+1];
				}
				if (cnt[i][j]&1) {
					tmp=g[i][j][cnt[i][j]-1];
					if (lst) t1[++a][1]=lst,t1[a][2]=tmp,lst=0;
					else lst=tmp;
				}
			}
	}
	for (int i=1;i<=ans;i++)
		cout<<s[t1[i][1]]<<' '<<s[t2[i][1]]<<endl,
		cout<<s[t1[i][2]]<<' '<<s[t2[i][2]]<<endl;
	return 0;
}