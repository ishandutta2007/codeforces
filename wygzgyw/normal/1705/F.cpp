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
typedef unsigned long long ull;
int flag;
int n;
string S,ans;
ull seed=2333;
ull rnd() {
	seed^=seed<<17;
	seed^=seed>>11;
	seed^=seed<<9;
	return seed;
}
int cnt;
int query(string &s) {
	if (!flag) cout<<s<<endl;
	cout.flush();
	cnt++;
	int x=0;
	if (flag) {
		for (int i=0;i<n;i++) if (s[i]==S[i]) x++;
	} else {
		cin>>x;
	}
	if (x==n) {
		if (flag) cerr<<cnt<<endl;
		exit(0);
	}
	return x;
}
int main() {
	cin>>n;
flag=0;
if (flag) { for (int i=0;i<n;i++) if (rnd()&1) S+='F'; else S+='T'; }
	string s1,s2;
	for (int i=0;i<n;i++) s1+='T',s2+='T',ans+='T';
	int all=query(s1);
	vector<int> X;
	int m=n/3*3;
	for (int i=m;i<n;i++) X.push_back(i);
	
	for (int i=0;i<m;i+=3) s2[i]='T',s2[i+1]='F',s2[i+2]='T';
	int A=query(s2);
	for (int i=0;i<m;i+=3) {
		string t=s1;
		t[i]=t[i+1]='F';
		int tmp=query(t)-all,F=0;
		if (tmp==2) ans[i]=ans[i+1]='F',F=1;
		else if (tmp==-2) ans[i]=ans[i+1]='T',F=1;
		else {
			t=s2;
			t[i]='F',t[i+1]='T',t[i+2]='F';
			tmp=query(t)-A;
			if (tmp==3) ans[i]='F',ans[i+1]='T',ans[i+2]='F';
			if (tmp==-3) ans[i]='T',ans[i+1]='F',ans[i+2]='T';
			if (tmp==1) ans[i]='F',ans[i+1]='T',ans[i+2]='T';
			if (tmp==-1) ans[i]='T',ans[i+1]='F',ans[i+2]='F';
		}
		if (F) X.push_back(i+2);
	}
	
	for (int &x : X) {
		string t=s1;
		t[x]='F';
		int tmp=query(t);
		if (tmp>all) ans[x]='F'; else ans[x]='T';
	}
	query(ans);
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