#include <bits/stdc++.h>
using namespace std;

#define file "file"
#define mp make_pair
#define pb push_back
#define xx real()
#define yy imag()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef complex<double> point;

#define DEBUG 0
#define dout if(DEBUG) cout

const int MAXN = 1e5 + 5;

char s[MAXN];
int d[MAXN];
bool used[MAXN];
int n;
bool was;

void dfs(int v){
    used[v] = 1;
    if(s[v] == '<'){
        if(v - d[v] < 0){
            was = 1; return;
        }
        else if(!used[v - d[v]]){
            dfs(v - d[v]);
        }
    }
    else{
        if(v + d[v] >= n){
            was = 1; return;
        }
        else if(!used[v + d[v]]){
            dfs(v + d[v]);
        }
    }
}

void solve(){
    cin >> n;
    scanf("%s", s);
    for(int i = 0; i < n; i++){
        scanf("%d", &d[i]);
    }
    dfs(0);
    if(was) cout << "FINITE";
    else cout << "INFINITE";
}

int main()
{
	#ifdef NASTYA
    assert(freopen("input.txt","r",stdin));
    assert(freopen("output.txt","w",stdout));
    #else
    //assert(freopen(file".in","r",stdin)); assert(freopen(file".out","w",stdout));
    #endif
	int t = 1;
	while(t--){
		solve();
	}
	return 0;
}