#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int n,m,id,x,y;
map<ll,set<pair<int,int> > > T;
set<pair<int,int> >::iterator it;
map<pair<int,int>,int> ans;
int gcd(int x,int y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
pair<int,int> f(int x,int y) {
	int z=gcd(x,y);
	return make_pair(x/z,y/z);
}
ll g(ll x,ll y) {
	return x*x+y*y;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(m);
	while (m--) {
		read(id); read(x); read(y);
		if (id==1) {
			n++;
			it=T[g(x,y)].begin();
			while (it!=T[g(x,y)].end())
				ans[f((*it).first+x,(*it).second+y)]+=2,it++;
			ans[f(x,y)]++;
			T[g(x,y)].insert(make_pair(x,y));
		} else if (id==2) {
			n--;
			ans[f(x,y)]--;
			T[g(x,y)].erase(make_pair(x,y));
			it=T[g(x,y)].begin();
			while (it!=T[g(x,y)].end())
				ans[f((*it).first+x,(*it).second+y)]-=2,it++;
		} else printf("%d\n",n-ans[f(x,y)]);
	}
	return 0;
}