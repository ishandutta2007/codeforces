// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=4010;
int used,tot=1,ch[maxn][20];
char t[maxn];
char s[maxn];
int fail[maxn],w[maxn];
int hd,tl,q[maxn];
void add(int len,int tmp) {
	int pos=1;
	for (int i=1;i<=len;i++) {
		int t=s[i]-'a';
		if (!ch[pos][t]) ch[pos][t]=++tot;
		pos=ch[pos][t];
	}
	w[pos]+=tmp;
}
vector<int> g[maxn];
void dfs(int x) {
	for (int &y : g[x]) w[y]+=w[x],dfs(y);
}
int dp[1<<12][maxn];
pair<short,int> from[1<<12][maxn];

int main() {
	//freopen("1.txt","r",stdin);
	int n; read(n);
	while (n--) {
		int W; read(W);
		scanf("%s",s+1);
		int len=strlen(s+1);
		int l=2000,r=l;
		int now=l;
		t[now]=s[1];
		used=(1<<(s[1]-'a'));
		int flag=1;
		for (int i=2;i<=len&&flag;i++) {
			int x=s[i]-'a';
			if (used>>x&1) {
				if (now>l&&t[now-1]==s[i]) now--;
				else if (now<r&&t[now+1]==s[i]) now++;
				else flag=0;
			} else {
				if (now==l) now--,l--,t[now]=s[i];
				else if (now==r) now++,r++,t[now]=s[i];
				else flag=0;
				used|=1<<x;
			}
		}
		if (!flag) continue;
		int tot=0;
		for (int i=l;i<=r;i++) s[++tot]=t[i];
		add(tot,W);
		reverse(s+1,s+tot+1);
		add(tot,W);
		//for (int i=1;i<=tot;i++) printf("%c",s[i]); puts("");
	}
	fail[1]=1;
    hd=1,tl=0;
    for (int i=0;i<12;i++)
        if (ch[1][i]) fail[ch[1][i]]=1,q[++tl]=ch[1][i];
        else ch[1][i]=1;
    while (hd<=tl) {
        int x=q[hd]; hd++;
        for (int i=0;i<12;i++) if (ch[x][i]) {
            fail[ch[x][i]]=ch[fail[x]][i];
            q[++tl]=ch[x][i];
        } else ch[x][i]=ch[fail[x]][i];
    }
    for (int i=2;i<=tot;i++) g[fail[i]].push_back(i);
    dfs(1); int INF=1e9;
    for (int t=0;t<(1<<12);t++) for (int now=1;now<=tot;now++) dp[t][now]=-INF;
    dp[0][1]=0;
    for (int t=0;t<(1<<12);t++) for (int now=1;now<=tot;now++) if (dp[t][now]!=-INF) for (int a=0;a<12;a++) if (!(t>>a&1)) {
		int tmp=dp[t][now]+w[ch[now][a]];
		if (dp[t|(1<<a)][ch[now][a]]<tmp) {
			dp[t|(1<<a)][ch[now][a]]=tmp;
			from[t|(1<<a)][ch[now][a]]=MP(a,now);
		}
	}
	int mx,ans=-INF;
	for (int now=1;now<=tot;now++) if (dp[(1<<12)-1][now]>=ans) ans=dp[(1<<12)-1][now],mx=now;
	string res;
	int t=(1<<12)-1;
	while (t) {
		int a=from[t][mx].first;
		res=res+(char)(a+'a');
		int b=from[t][mx].second;
		mx=b,t^=1<<a;
	}
	reverse(res.begin(),res.end());
	cout<<res<<endl;
	return 0;
}