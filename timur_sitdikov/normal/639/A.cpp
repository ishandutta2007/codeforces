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

const int MAXN = 1e6 + 5;

int t[MAXN];
int open[MAXN], top;

void solve(){
    int n, k, q;
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++){
        scanf("%d", &t[i]);
    }
    int tp, id;
    top = 0;
    for(int i = 0; i < q; i++){
        scanf("%d%d", &tp, &id);
        if(tp == 1){
            if(top < k){
                open[top++] = id;
            }
            else{
                int mn = 0;
                for(int j = 1; j < top; j++){
                    if(t[open[mn]] > t[open[j]]){
                        mn = j;
                    }
                }
                if(t[open[mn]] < t[id]){
                    open[mn] = id;
                }
            }
        }
        else{
            bool opened = 0;
            for(int j = 0; j < top; j++){
                if(open[j] == id){
                    opened = 1; break;
                }
            }
            if(opened) printf("YES\n");
            else printf("NO\n");
        }
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