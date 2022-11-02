#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n,m;
char s[10];
int c1,c2,in[maxn],out[maxn];
ll ex[maxn];
map<pair<int,int>,int> M;
void add(int x,int y) {
	int a=M[make_pair(x,y)],b=M[make_pair(y,x)];
	if (a==b) c2++;
	c1++;
}
void del(int x,int y) {
	int a=M[make_pair(x,y)],b=M[make_pair(y,x)];
	if (a==b) c2--;
	c1--;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	int x,y,k;
	
	while (m--) {
		scanf("%s",s+1);
		if (s[1]=='+') {
			read(x),read(y); scanf("%s",s+1);
			M[make_pair(x,y)]=s[1]-'a'+1;
			if (M[make_pair(y,x)]) {
				add(x,y);
			}
		} else if (s[1]=='-') {
			read(x),read(y);
			if (M[make_pair(y,x)]) del(x,y);
			M[make_pair(x,y)]=0;
		} else {
			read(k);
			if (k%2==0) {
				if (c2) puts("YES"); else puts("NO");
			} else {
				if (c1) puts("YES"); else puts("NO");
			}
		}
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