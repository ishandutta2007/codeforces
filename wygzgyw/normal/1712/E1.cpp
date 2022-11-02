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
const int maxn=(2e5)+10;
int T;
vector<int> d[maxn];
vector<pair<int,int> > vec[maxn];
namespace BIT {
ll tr[maxn];
void add(int x,int y) { for (;x;x-=x&(-x)) tr[x]+=y; }
ll query(int x) { ll res=0; for (;x<maxn;x+=x&(-x)) res+=tr[x]; return res; }
};
ll ans[maxn];
int l,r;
int calc(int x,int y) {
	int r=::r,l=::l; r=r/y,l=(l%x==0?l/x:l/x+1);
	return max(r-l+1,0);
}
ll res[maxn];
ll C3(ll x) { return x*(x-1)*(x-2)/6; }
int main() {
	read(T);
	for (int i=1;i<=T;i++) {
		read(l),read(r);
		res[i]=C3(r-l+1);
		vec[r].push_back(MP(l,i));
		ans[i]=calc(3,6)+calc(6,15);
	}
	for (int i=1;i<maxn;i++) for (int j=i;j<maxn;j+=i) d[j].push_back(i);
	for (int i=1;i<maxn;i++) {
		int sz=(int)d[i].size();
		for (int j=0;j<sz-2;j++) BIT::add(d[i][j],sz-j-2);
		for (auto [x,y] : vec[i]) ans[y]+=BIT::query(x);
	}
	for (int i=1;i<=T;i++) writeln(res[i]-ans[i]);
	return 0;
}