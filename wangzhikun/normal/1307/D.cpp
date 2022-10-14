#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

const int MAXN = 1e6 + 10;
typedef pair<ll, int> pli;

struct Dijkstra{
	int s;
	vector<pii> G[MAXN];
	priority_queue<pli, vector<pli>, greater<pli>> Q;
	
	ll dis[MAXN];
	void addedge(int u,int v,int w){
		G[u].push_back(make_pair(v, w));
	}
	void calcdis(){
		Q.push(make_pair(0, s));
		memset(dis, -1, sizeof(dis));
		while(!Q.empty()) {
			pli cur = Q.top(); Q.pop();
			if(~dis[cur.second]) continue;
			dis[cur.second] = cur.first;
			for(vector<pii>::iterator i = G[cur.second].begin(); i != G[cur.second].end(); i++)
				Q.push(make_pair(cur.first + i->second, i->first));
		}
	}
}A,B;


int n,m,k,cc,u,v;
int mk[200020];
int main() {
	read(n);read(m);read(k);
	for(int i=1;i<=k;i++){
		read(cc);
		mk[cc] = 1;
	}
	A.s = 1;
	B.s = n;
	for(int i=1;i<=m;i++){
		read(u);read(v);
		A.addedge(u,v,1);
		A.addedge(v,u,1);
		B.addedge(u,v,1);
		B.addedge(v,u,1);
	}
	A.calcdis();
	B.calcdis();
	vector<pii> P;
	int ans = A.dis[n];
	for(int i=1;i<=n;i++){
		if(mk[i]){
			P.push_back(make_pair(A.dis[i],B.dis[i]));
		}
	}
	sort(P.begin(),P.end());
	int l = 0,r = 1000000;
	while(l+1!=r){
		int mid = (l+r)/2;
		vector<pii> Q;
		int ok = 0;
		for(auto ct:P){
			Q.push_back(make_pair(mid-ct.second-1,mid-ct.first-1));
		}
		sort(Q.begin(),Q.end());
		reverse(Q.begin(),Q.end());
		int p = P.size()-1,cmx = -1e9,cmx2 = -1e9;
		for(auto ct:Q){
			while(p>=0 && P[p].first>=ct.first){
				int cc = P[p].second;
				if(cc>=cmx){
					cmx2 = cmx;
					cmx = cc;
				}else{
					cmx2 = max(cmx2,cc);
				}
				p--;
			}
			if(cmx2>=ct.second)ok = 1;
			else{
				int ori1 = -ct.second-1+mid,ori2 = -ct.first-1+mid;
				if(cmx>=ct.second && !(ori1>=ct.first && ori2>=ct.second))ok = 1;
			}
		}
		if(ok){
			l = mid;
		}else{
			r = mid;
		}
	}
	//cout<<ans<<' '<<l<<endl;
	cout<<min(l,ans)<<endl;
	
	return 0;
}