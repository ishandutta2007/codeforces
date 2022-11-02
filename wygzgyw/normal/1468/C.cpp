#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(5e5)+10;
int q,x,op,cnt,m[maxn];
set<pair<int,int> > s;
set<int> t;
set<pair<int,int> > :: iterator its;
set<int> :: iterator itt;
void del(int x) {
	s.erase(make_pair(m[x],x));
	t.erase(x);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(q);
	while (q--) {
		read(op);
		if (op==1) {
			read(x); x=-x; cnt++; m[cnt]=x;
			s.insert(make_pair(x,cnt));
			t.insert(cnt);
		} else if (op==2) {
			itt=t.begin();
			x=(*itt);
			del(x);
			printf("%d ",x);
		} else {
			its=s.begin();
			x=(*its).second;
			del(x);
			printf("%d ",x);
		}
	} puts("");
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/