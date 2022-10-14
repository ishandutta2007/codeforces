#include <bits/stdc++.h>
#define double long double
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " +
           to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

typedef pair<int,double> pid;
int n,q,a[100010];

struct val{
	int l,r;
	double p;
	bool operator < (const val &rhs) const{
		if(l!=rhs.l)return l<rhs.l;
		return r>rhs.r;
	}
}V[5050];

stack<int> S;
vector<int> G[5050];

vector<pid> P[5050];

void dfs(int num){
	int cmx = 0;
	if(G[num].size() == 0){
		for(int i= V[num].l;i<=V[num].r;i++)cmx = max(cmx,a[i]);
	}else{
		for(int i= V[num].l;i<V[G[num][0]].l;i++)cmx = max(cmx,a[i]);
		for(int i= V[G[num].back()].l+1;i<=V[num].r;i++)cmx = max(cmx,a[i]);
		for(int i=0;i<G[num].size()-1;i++)
			for(int j=V[G[num][i]].r+1;j<V[G[num][i+1]].l;j++)cmx = max(cmx,a[j]);
	}
	vector<pid> CC;
	CC.push_back(make_pair(cmx,1));
	for(auto ct:G[num]){
		dfs(ct);
		debug(CC,ct);
		if(P[ct].back().first<CC[0].first)continue;
		if(P[ct][0].first>CC.back().first){
			CC = P[ct];
			continue;
		}
		int N = max(P[ct].back().first,CC.back().first);
		vector<double> cmp(CC.size()+P[ct].size(),0);
		for(auto a:CC){
			for(auto b:P[ct]){
				cmp[N-max(a.first,b.first)]+=a.second*b.second;
			}
		}
		CC.clear();
		for(int i=cmp.size()-1;i>=0;i--){
			CC.push_back(make_pair(N-i,cmp[i]));
		}
		debug(CC);
	}
	CC.push_back(make_pair(CC.back().first+1,0));
	for(int i= CC.size()-2;i>=0;i--){
		CC[i+1].second+=CC[i].second*V[num].p;
		CC[i].second*=1.0-V[num].p;
	}
	P[num] = CC;
	debug(num,P[num],V[num].l,V[num].r,V[num].p);
}

int main() {
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	V[0].l = 1;V[0].r = n;V[0].p = 0;
	for(int i=1;i<=q;i++){
		cin>>V[i].l>>V[i].r>>V[i].p;
	}
	q++;
	sort(V,V+q);
	for(int i=0;i<q;i++){
		while(!S.empty() && V[i].l>V[S.top()].r)S.pop();
		if(!S.empty())G[S.top()].push_back(i);
		S.push(i);
	}
	dfs(0);
	debug(G[0]);
	debug(P[0]);
	double ans  = 0;
	for(auto ct:P[0])ans+=ct.first*ct.second;
	cout<<setprecision(15)<<fixed<<ans<<endl;
	return 0;
}