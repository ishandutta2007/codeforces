#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n, len[2000005], nad[2000005], pod[2000005];
int bottom = 1000000;
void merge(int a, int b, int to){
    int l1 = len[a];
    int nad1 = nad[a];
    int pod1 = pod[a];
    int l2 = len[b];
    int nad2 = nad[b];
    int pod2 = pod[b];
    len[to] = l1 + l2 + std::min(nad1, pod2)*2;
    nad[to] = nad2 + nad1 - std::min(nad1, pod2);
    pod[to] = pod1 + pod2 - std::min(nad1, pod2);
}

void build(int v){
    if(v >= bottom) return;
    build(v<<1);
    build((v<<1)+1);
    merge(v<<1, (v<<1)+1, v);
}

const int M = 2*bottom+2;

int query(int a, int b){
    a += bottom;
    b += bottom+1;
    len[M] = pod[M] = nad[M] = 0;
    VI v1, v2;
    while(a < b){
        if(a & 1) v1.push_back(a++);
        if(b & 1) v2.push_back(--b);
        a >>= 1;
        b >>= 1;
    }
    while(!v2.empty()) v1.push_back(v2.back()), v2.pop_back();
    FOR(i, SZ(v1)) merge(M, v1[i], M);
    return len[M];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string str;
	std::cin >> str;
	n = SZ(str);
	FOR(i, n){
	    if(str[i] == '(') nad[bottom+i]++;
	    else pod[bottom+i]++;
	}
	build(1);
	int m;
	std::cin >> m;
	FOR(i, m){
	    int a, b;
	    std::cin >> a >> b;
	    a--;b--;
	    std::cout << query(a, b) << "\n";
	}
	return 0;
}