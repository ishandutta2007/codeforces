#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int n, m, x, y, z;
vector<vector<pii>> g;

struct readInt{
	readInt& operator>>(int &_x){
		char c = _x = 0;
		while(c < 48) c = _getchar_nolock();
		while(c > 47) _x = _x * 10 + c - 48, c = _getchar_nolock();
		return *this;
	}
#define cin __read__
} __read__;


template<class T> struct heap{
	vector<T> a = vector<T> (1);
	void pop(){
		a[1] = a.back(); a.pop_back();
		size_t i = 1, j;
		while(2*i < size(a)){
			j = (2*i+1 < size(a) && a[2*i+1] < a[2*i]);
			if(a[2*i|j] < a[i])
				a[i].swap(a[2*i|j]), i = 2*i|j;
			else break;
		}
	}
	void push(T v){
		int i = size(a); a.push_back(v);
		while(i > 1 && a[i] < a[i/2])
			a[i].swap(a[i/2]), i /= 2;
	}
	T top(){ return a[1]; }
	bool empty(){ return size(a) == 1; }
};
 
int32_t main(){
    cin >> n >> m;
    int d[n+1], done[n+1], p[n+1];
    for(int i=1; i<=n; ++i) d[i] = 1000000000000;
    for(int i=1; i<=n; ++i) p[i] = -1;
    for(int i=1; i<=n; ++i) done[i] = 0;
    d[1] = 0;
    g.resize(n+1);
    for(int i=0; i<m; ++i){
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    heap<pii> q;
    q.push({0, 1});
    // done[1] = 1;
    while(!q.empty()){
        auto [dist, u] = q.top(); q.pop();
        if(done[u]) continue;
        done[u] = 1;
        for(auto [v, weight]: g[u]){
            if(d[v]>weight+d[u]){
                d[v] = weight+d[u];
                p[v] = u;
            }
            q.push({d[v], v});
        }
    }
    if(d[n]==1000000000000) cout << -1;
    else{
        int curr = n;
        vector<int> path;
        while(p[curr]!=-1){
            path.push_back(curr);
            curr = p[curr];
        } path.push_back(1);
        reverse(path.begin(), path.end());
        for(int i=0; i<path.size(); ++i){
            cout << path[i] << " ";
        }
    }
}