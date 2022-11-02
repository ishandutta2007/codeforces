#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,mid,tot,cnt[110][27];
int c[110][27];
bool vis[10010];
string s[10010],t[110];
char ans[110];
int len;
void solve(int l,int r) {
	if (l>r) return;
	tot=0;
	printf("? %d %d\n",l,r);
	fflush(stdout);
	len=r-l+1;
	for (int i=1;i<=len*(len+1)/2;i++) cin>>s[++tot];
	if (l==r) { ans[l]=s[1][0]; return; }
	printf("? %d %d\n",l,r-1);
	fflush(stdout);
	len=r-l;
	for (int i=1;i<=len*(len+1)/2;i++) cin>>s[++tot];
	for (int i=1;i<=tot;i++) sort(s[i].begin(),s[i].end());
	sort(s+1,s+tot+1);
	for (int i=1;i<tot;i++)
		if (!vis[i]&&s[i]==s[i+1]) vis[i]=vis[i+1]=1;
	for (int i=1;i<=tot;i++)
		if (!vis[i]) t[s[i].size()]=s[i];
	//for (int i=1;i<=n;i++) cout<<t[i]<<endl;
	memset(cnt,0,sizeof(cnt));
	len=r-l+1;
	for (int i=1;i<=len;i++) {
		for (int j=0;j<i;j++) cnt[i][t[i][j]-'a']++;
	}
	ans[r]=t[1][0];
	for (int i=2;i<=len;i++) {
		for (int j=0;j<26;j++)
			if (cnt[i][j]!=cnt[i-1][j]) {
				ans[len-i+l]=j+'a';
				break;
			}
	}	
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	mid=(n+1)/2;
	solve(1,mid);
	if (n==1) { printf("! %s\n",ans+1); return 0; }
	printf("? 1 %d\n",n); fflush(stdout);
	tot=0;
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=n*(n+1)/2;i++) {
		cin>>s[++tot];
		len=s[tot].size();
		for (int j=0;j<len;j++)
			cnt[len][s[tot][j]-'a']++;
	}
	for (int i=0;i<=n;i++) {
		for (int j=0;j<26;j++)
			c[i+1][j]=cnt[i+1][j]-cnt[i][j];
	}
	int x,y;
	for (int i=2;i-1<=n-i+2;i++) {
		x=y=-1;
		for (int j=0;j<26;j++)
			if (c[i-1][j]-c[i][j]>0) {
				if (x==-1) x=j; else y=j;
			}
		//printf("%d %d %c %c\n",i-1,n-i+2,x+'a',y+'a');
		if (y==-1) ans[n-i+2]='a'+x;
		else if ('a'+x==ans[i-1]) ans[n-i+2]='a'+y;
		else ans[n-i+2]='a'+x;
	}
	printf("! %s\n",ans+1);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/