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

const int MAXN = 5e3 + 2;
const int INF = 1e9;

int col[MAXN];
int ans[MAXN];
int cnt[MAXN];

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &col[i]);
        col[i]--;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cnt[j] = 0;
        }
        pii mx = mp(-1, -1);
        for(int j = i; j < n; j++){
            cnt[col[j]]++;
            if(cnt[col[j]] > mx.first || cnt[col[j]] == mx.first &&
               col[j] < mx.second){
                mx = mp(cnt[col[j]], col[j]);
            }
            ans[mx.second]++;
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ", ans[i]);
    }
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