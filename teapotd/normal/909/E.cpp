#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define repd(i,b,e)for(int i=(b);i>=(e);i--)
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define sz(x)int((x).size())
#define TM template<class T,class U=int,class...V>
#define DF(t,...)TM auto operator<<(ostream&o,__VA_ARGS__ x)->decltype(t,cout)
#define DD(...)void print(){cerr<<'{';debx(#__VA_ARGS__,__VA_ARGS__);cerr<<'}';}
#ifdef LOC
#define deb(...)(cerr<<"<"<<__LINE__,debx("> "#__VA_ARGS__,__VA_ARGS__),cerr<<"\n")
#else
#define deb(...)
#endif
using namespace std;using namespace rel_ops;using ll=int64_t;using Vi=vector<int>;using Pii=pair<int,int>;
void debx(...){}TM void debx(T s,U a,V...b){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;debx(s,b...);}
DF(&T::print,T){x.print();return o;}DF(0,pair<T,U>){return o<<"("<<x.first<<", "<<x.second<<")";}
DF(T().begin(),T){o<<"[";each(e,x)o<<e<<", ";return o<<"]";}

// ----------------------------------------------------------------------------------------------------- //

struct Vert {
	Vi edges, invEdges;
	int coproc, out{0};
};

int V, E;
vector<Vert> verts;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> V >> E;
	verts.resize(V);

	each(v, verts) cin >> v.coproc;

	rep(i, 0, E) {
		int a, b; cin >> a >> b;
		verts[a].edges.pb(b);
		verts[b].invEdges.pb(a);
		verts[a].out++;
	}

	queue<int> avail, coproc;

	rep(i, 0, V) if (verts[i].out == 0) {
		if (verts[i].coproc) coproc.push(i);
		else avail.push(i);
	}

	int ret = 0;

	while (true) {
		while (!avail.empty()) {
			int v = avail.front();
			avail.pop();

			each(e, verts[v].invEdges) if (--verts[e].out == 0) {
				if (verts[e].coproc) coproc.push(e);
				else avail.push(e);
			}
		}

		if (coproc.empty()) break;
		ret++;

		while (!coproc.empty()) {
			int v = coproc.front();
			coproc.pop();

			each(e, verts[v].invEdges) if (--verts[e].out == 0) {
				if (verts[e].coproc) coproc.push(e);
				else avail.push(e);
			}
		}
	}

	cout << ret << endl;
	return 0;
}