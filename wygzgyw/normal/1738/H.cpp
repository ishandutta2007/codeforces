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
const int maxn=(1e6)+10;
int q;
char s[10];
char t[maxn];
int fail[maxn],len[maxn],tot;
int l,r,lst,ans;
int ch[maxn][26],son[maxn];
void extend(int c,int n) {
    int p=lst,q;
    while (t[n-len[p]-1]!=t[n]) p=fail[p];
    if (!ch[p][c]) {
        tot++;
        len[tot]=len[p]+2;
        q=fail[p];
        while (t[n-len[q]-1]!=t[n]) q=fail[q];
        fail[tot]=ch[q][c];
        ch[p][c]=tot;
    }
    lst=ch[p][c];
}
int tag[maxn];
vector<int> vec[maxn];
void puttag(int root,int x) {
	if (root<=1) return;
	if (!tag[root]) ans++,son[fail[root]]++;
	if (tag[root]<x) tag[root]=x,vec[x-len[root]+1].push_back(root);
}
int main() {
	tot=1; fail[0]=fail[1]=1;
    len[0]=0; len[1]=-1;
    l=1,r=0;
	read(q);
	while (q--) {
		scanf("%s",s);
		if (s[1]=='u') {
			scanf("%s",s);
			t[++r]=s[0];
			extend(s[0]-'a',r);
			while (len[lst]>r-l+1) lst=fail[lst];
			puttag(lst,r);
		} else {
			for (int &x : vec[l]) if (!son[x]&&tag[x]-len[x]+1==l) {
				puttag(fail[x],tag[x]);
				son[fail[x]]--;
				ans--;
				tag[x]=0;
			}
			l++;
		}
		printf("%d\n",ans);
	}
	return 0;
}