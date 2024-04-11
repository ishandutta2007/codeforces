//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 5;
const int inf = (int)1e9;

#define data fhfh

struct data{
    int value;
    int min;
    int add = 0;
};

data F[N], S[N];
int szf = 0, szs = 0;

void push(int x){
    F[szf].value = x;
    F[szf].add = 0;
    F[szf].min = x;
    F[szf].min = min(F[szf].min, szf ? F[szf-1].min : F[szf].min);
    ++szf;
}

void pop(){
    if(!szs){
        int carry = 0;
        while(szf){
            S[szs].add = 0;
            S[szs].value = F[szf-1].value + carry;
            S[szs].min = S[szs].value;
            S[szs].min = min(S[szs].min, szs ? S[szs-1].min : S[szs].min);
            carry += F[szf-1].add;
            ++szs;
            --szf;
        }
    }
    if(szs > 1){
        S[szs-2].add += S[szs-1].add;
        S[szs-2].value += S[szs-1].add;
        S[szs-2].min += S[szs-1].add;
    }
    --szs;
}

int get(){
    int ans = inf;
    if(szs)
        ans = min(ans, S[szs-1].min);
    if(szf)
        ans = min(ans, F[szf-1].min);
    ret ans;
}

void inc(){
    if(szf){
        ++F[szf-1].min;
        ++F[szf-1].value;
        ++F[szf-1].add;
    }
    if(szs){
        ++S[szs-1].min;
        ++S[szs-1].value;
        ++S[szs-1].add;
    }
}

int n, m;
bool used[N];
vector<int> gr[N];
int w[N];
int c[N];
int sz = 0;

void dfs(int v){
    ++w[sz];
    used[v] = true;
    I(u, gr[v])
        if(!used[u])
            dfs(u);
}

int dp[2][N];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> m;
    F(i, 0, m){
        int v, u;
        cin >> v >> u;
        --v; --u;
        gr[v].pb(u);
        gr[u].pb(v);
    }
    F(i, 0, n){
        if(!used[i]){
            dfs(i);
            ++sz;
        }
    }
    int maxs = n;
    n = sz;
    sort(w, w + n);
    int ptr = -1;
    F(i, 0, n){
        if(!i || w[i] != w[i - 1]){
            ++ptr;
            c[ptr] = 1;
        }
        else{
            ++c[ptr];
        }
    }
    ++ptr;
    n = unique(w, w + n) - w;
    fill(dp[0], dp[0] + N, inf);
    fill(dp[1], dp[1] + N, inf);
    int tc = 0;
    dp[1][0] = 0;
    F(i, 0, n){
        F(j, 0, w[i]){
            szf = szs = 0;
            for(int k = j; k <= maxs; k += w[i]){
                if(szf + szs)
                    dp[tc][k] = min(dp[1 - tc][k], get());
                else
                    dp[tc][k] = dp[1 - tc][k];
                push(dp[1 - tc][k]);
                if(szf + szs > c[i])
                    pop();
                inc();
            }
        }
        tc ^= 1;
    }
    int ans = inf;
    E(i, 1, maxs){
        bool ok = 1;
        int j = i;
        while(j){
            if(j%10 != 4 && j%10 != 7){ok = 0; break;}
            j /= 10;
        }
        if(ok)
            ans = min(ans, dp[1 - tc][i]);
    }
    if(ans == inf)ans = 0;
    cout << ans - 1 << endl;
	return 0;
}