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
typedef long long ll;
const int mod=998244353;
int fib[1000];
int get(int n) {
	if (n<=1) return n^1;
	int t=upper_bound(fib,fib+32,n)-fib-1;
	return get(n-fib[t]);
}
vector<pair<int,int> > suf,tmp;
int sum,dp;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
void add(int x) {
	tmp.clear();
	if (x) tmp.push_back(MP(1,dp));
	int now=sum; update(now,mod-dp);
	for (auto [len,val] : suf) if (x==get(len)) {
		tmp.push_back(MP(len+1,val));
		int t=lower_bound(fib,fib+32,len+1)-fib;
		if (fib[t]==len+1) update(now,mod-val);
	}
	dp=now,update(sum,dp);
	suf.swap(tmp);
}
char s[3010];
int main() {
	fib[0]=1;
	fib[1]=2;
	for (int i=2;i<=31;i++) fib[i]=fib[i-1]+fib[i-2];
	int n; read(n);
	dp=sum=1;
	while (n--) {
		scanf("%s",s+1);
		int len=strlen(s+1);
		for (int i=1;i<=len;i++) add(s[i]-'0');
		printf("%d\n",dp);
	}
	return 0;
}