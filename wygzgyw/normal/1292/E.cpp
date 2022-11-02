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
const int xyr=1;
int T,n;
string ans;
char t[60]; double all;
int query(string s) {
	int len=s.size(); all+=1.0/len/len;
	printf("? "); for (int i=0;i<len;i++) putchar(s[i]); puts(""); fflush(stdout);
	int x=0,y;
	if (xyr) {
		scanf("%d",&x);
		for (int i=1;i<=x;i++) {
			scanf("%d",&y); y--;
			for (int j=y;j<y+len;j++) ans[j]=s[j-y];
		}
	} else {
		for (int i=0;i+len-1<n;i++) {
			int flag=1; for (int j=i;j<i+len;j++) flag&=(t[j]==s[j-i]);
			if (flag) {
				x++;
				for (int j=i;j<i+len;j++) ans[j]=t[j];
			}
		}
	}
	return x;
}
int tmp;
vector<char> P[10];
void dfs(int x,string &s) {
	if (tmp<0) return;
	if (x==n) {
		tmp--; if (tmp==0) { ans=s; return; }
		if (query(s)) ans=s,tmp=-1;
		return;
	}
	if (s[x]>0) dfs(x+1,s);
	else {
		for (char &a : P[x]) s[x]=a,dfs(x+1,s); s[x]=0;
	}
}
int main() {
//	freopen("1.txt","r",stdin);
	scanf("%d",&T); while (T--) {
		all=0;
		scanf("%d",&n); if (!xyr) scanf("%s",t);
		ans.resize(n);
		for (int i=0;i<n;i++) ans[i]=0;
		if (n>4) {
			query("CC"),query("CH"),query("CO");
			query("HO"),query("OO");
			for (int i=1;i<n-1;i++) if (!ans[i]) ans[i]='H';
			// ans[1]=O,H
			// ans[n]=C,H
			if (!ans[0]&&!ans[n-1]) {
				ans[0]='O',ans[n-1]='H'; int flag=query(ans)>0;
				if (!flag) ans[0]='O',ans[n-1]='C',flag|=query(ans)>0;
				if (!flag) ans[0]='H',ans[n-1]='C',flag|=query(ans)>0;
				if (!flag) ans[0]='H',ans[n-1]='H';
			} else if (!ans[0]&&ans[n-1]) {
				ans[0]='O'; if (!query(ans)) ans[0]='H';
			} else if (!ans[n-1]&&ans[0]) {
				ans[n-1]='C'; if (!query(ans)) ans[n-1]='H';
			}
		} else {
			int cnt=query("CC")+query("CH")+query("CO");
			if (cnt||query("HO")) {
				for (int i=0;i<=2;i++) P[i]={'O','H'};
				P[3]={'O','H','C'}; tmp=1;
				for (int i=0;i<n;i++) if (!ans[i]) tmp*=(int)P[i].size();
				string ANS=ans; dfs(0,ANS);
			} else if (query("OO")) {
				if (!ans[n-1]&&ans[n-2]) { // OOO*
					ans[n-1]='C'; if (!query(ans)) ans[n-1]='H';
				} else if (!ans[n-1]&&!ans[n-2]) { // OO**
					ans[n-2]='H'; ans[n-1]='C'; if (!query(ans)) ans[n-1]='H';
				}
			} else {
				ans[1]=ans[2]='H';
				query("HHH");
				if (!ans[0]) ans[0]='O';
				if (!ans[3]) ans[3]='C';
			}
		}
		for (int i=0;i<n;i++) assert(ans[i]>0);
		printf("! "); for (int i=0;i<n;i++) putchar(ans[i]); puts(""); fflush(stdout);
		if (!xyr) {
			for (int i=0;i<n;i++) assert(ans[i]==t[i]);
			printf("all=%.5lf\n",all);
		} else scanf("%d",&n);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/