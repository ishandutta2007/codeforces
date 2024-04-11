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
typedef vector<int> poly;
char s[40];
int n;
ll ans;
poly P;
void init(poly &A) {
	int a=(int)A.size()-1;
	if (a<n-1) return;
	for (int i=a;i>=n-1;i--) if (A[i]) {
		for (int j=i,k=n-1;j>=i-n+1;j--,k--) A[j]^=P[k];
	}
	while ((int)A.size()&&!A.back()) A.pop_back();
}
poly operator * (poly A,poly B) {
	int a=(int)A.size(),b=(int)B.size();
	poly res(a+b-1,0);
	for (int i=0;i<a;++i) for (int j=0;j<b;++j)
		res[i+j]^=A[i]&B[j];
	init(res);
	return res;
}
int B=1<<18;
ll Hash(poly &A) {
	ll res=0;
	for (int i=0;i<A.size();i++) if (A[i]) res|=1LL<<i;
	return res;
}
map<ll,int> M;
poly res;
void cheng2(poly &A) {
	A.push_back(0);
	for (int i=(int)A.size()-1;i>0;i--) A[i]=A[i-1]; A[0]=0; init(A);
}
poly operator + (poly A,poly B) {
	while ((int)A.size()<(int)B.size()) A.push_back(0);
	for (int i=0;i<A.size()&&i<B.size();i++) A[i]^=B[i];
	return A;
}
void chu2(poly &A) {
	if (A[0]==0) { for (int i=0;i<(int)A.size()-1;i++) A[i]=A[i+1]; A.pop_back(); }
	else { A=A+P; chu2(A); }
}
void print(poly A) { for (int i=0;i<A.size();i++) printf("%d ",A[i]); puts(""); }
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%s",s+1); n=strlen(s+1);
	while (s[n]=='0'&&n) n--;
	if (n==0) { puts("-1"); return 0; }
	int rem=0;
	for (int i=1;i<=n;i++) if (s[i]=='1') { rem=i; break; }
	n=n-rem+1;
	if (n==1) { printf("%d %d\n",rem,rem+1); return 0; }
	P.resize(n);
	for (int i=rem;i<=rem+n-1;i++) P[i-rem]=s[i]-'0';
	poly tmp={1},base={0,1};
	poly R1,R2;
	//int tst=37452687-6;
	poly R3=tmp;
	for (int i=0;i<B;i++) {
		ll t=Hash(tmp);
		//if (i==228233) { R1=tmp; printf(">  %lld\n",t); }
		if (i&&!M.count(t)) {
			M[t]=i;
		}
		chu2(tmp);
		R3=R3*base;
	}
	//exit(0);
	base=R3; tmp={1};
	poly iv;
	for (ll i=0;i<B;i++) {
		ll t=Hash(tmp);
		//if (i==142) printf("? %lld\n",t);
		if (M.count(t)) { ans=i*B+M[t]; break; }
		tmp=tmp*base;
		if (i==0) M[1]=0;
	}
	//cout<<tst%B<<" "<<tst/B<<endl;
//	printf("? %lld\n",ans);
	printf("%d %lld\n",rem,rem+ans);
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