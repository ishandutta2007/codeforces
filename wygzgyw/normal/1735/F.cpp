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

const int maxn=(3e5)+10;
int T;
int n;
int a,b;
pair<long double,long double> l,r;
struct node {
	long double X,Y;
	friend bool operator < (node A,node B) { return A.Y*B.X<B.Y*A.X; }
};
multiset<node> s;
multiset<node>::iterator it;
long double p[maxn],q[maxn];
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(a),read(b);
		s.clear();
		l=r=MP(a,b);
		for (int i=1;i<=n;i++) read(p[i]);
		for (int i=1;i<=n;i++) read(q[i]);
		if (!a&&!b) { for (int i=1;i<=n;i++) puts("0"); continue; }
		for (int i=1;i<=n;i++) {
		//	long double k=q[i]/p[i];
		//	long double len=2*p[i];
		//	printf("%.5lf %.5lf\n",k,len);
			s.insert((node){2*p[i],2*q[i]});
			l.first-=p[i],l.second+=q[i];
			r.first+=p[i],r.second-=q[i];
			while (r.second<0&&(int)s.size()) {
				it=--s.end();
				node A=(*it);
				//k=A.first,len=A.second;
				if (r.second+A.Y>0) {
					s.erase(it);
					long double delta=-r.second*A.X/A.Y;
					s.insert((node){A.X-delta,A.Y+r.second});
					r.first-=delta; r.second+=delta*A.Y/A.X;
					break;
				} else {
					r.first-=A.X,r.second+=A.Y,s.erase(it);
				}
			}
			while (l.first<0&&(int)s.size()) {
				it=s.begin();
				node A=(*it);
				//k=A.first,len=A.second;
				if (l.first+A.X>0) {
					s.erase(it);
					long double delta=-l.first;
					s.insert((node){A.X-delta,A.Y+l.first*A.Y/A.X});
					l.first+=delta; l.second-=delta*A.Y/A.X;
					break;
				} else {
					l.first+=A.X,l.second-=A.Y,s.erase(it);
				}
			}
		//	for (pair<long double,long double> A : s) printf("%.5lf,%.5lf\n",A.first,A.second);
			printf("%.10Lf\n",r.first);
		}
	}
	return 0;
}