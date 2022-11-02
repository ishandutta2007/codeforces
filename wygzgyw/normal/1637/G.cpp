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
const int maxn=(1e5)+10;
int T,n,rem[maxn],a[maxn];
vector<pair<int,int> > solve(int n) {
	if (n<=2) return {};
	if (rem[n]==n) return solve(n-1);
	int p=rem[n]/2;
	vector<pair<int,int> > ans,A,B;
	for (int i=1;i<=n-p;i++) ans.push_back(MP(p-i,p+i));
	A=solve(p-(n-p)-1);
	for (pair<int,int> &a : A) ans.push_back(a);
	B=solve(n-p);
	for (pair<int,int> &b : B) ans.push_back(MP(b.first*2,b.second*2));
	return ans;
}
vector<pair<int,int> > ans;
void check() {
	multiset<int> s;
	for (int i=1;i<=n;i++) s.insert(i);
	for (pair<int,int> &a : ans) {
		int x=a.first,y=a.second;
		s.erase(s.find(x)),s.erase(s.find(y));
		s.insert(x+y),s.insert(abs(x-y));
	}
	for (int i : s) printf("%d ",i); puts("");
	exit(0);
}
int main() {
	//freopen("1.txt","r",stdin);
	for (int i=1;i<maxn;i++) {
		rem[i]=1; while (rem[i]<i) rem[i]*=2;
	}
	read(T);
	while (T--) {
		read(n);
		if (n==2) { puts("-1"); continue; }
		ans=solve(n);
		multiset<int> s;
		for (int i=1;i<=n;i++) s.insert(i);
		for (pair<int,int> &a : ans) {
			int x=a.first,y=a.second;
			s.erase(s.find(x)),s.erase(s.find(y));
			s.insert(x+y),s.insert(abs(x-y));
		}
		for (int i : s) if (s.count(i)>1) {
			ans.push_back(MP(i,i));
			s.erase(s.find(i)),s.erase(s.find(i));
			s.insert(0),s.insert(2*i); break;
		}
		int tar=rem[n],cnt=0;
		for (int i : s) if (i!=0) {
			int x=i;
			while (x!=tar) ans.push_back(MP(0,x)),ans.push_back(MP(x,x)),x*=2;
		} else cnt++;
		while (cnt--) ans.push_back(MP(0,tar));
		printf("%d\n",(int)ans.size());
		//check();
		for (pair<int,int> &A : ans) printf("%d %d\n",A.first,A.second);
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