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

const int MAXN = 2e6 + 5;

int ans[MAXN];
int ans2[MAXN];

void solve(){
    int n, q;
    cin >> n >> q;
    int tp, x;
    int pos[2];
    pos[0] = 0;
    pos[1] = 1;
    for(int i = 0; i < q; i++){
        scanf("%d", &tp);
        if(tp == 1){
            scanf("%d", &x);
            for(int j = 0; j < 2; j++){
                pos[j] = (pos[j] + x + n) % n;
            }
        }
        else{
            for(int j = 0; j < 2; j++){
                if(pos[j] & 1){
                    pos[j]--;
                }
                else{
                    pos[j]++;
                }
            }
        }
    }
    ans[0] = pos[0];
    ans[1] = pos[1];
    for(int i = 2; i < n; i += 2){
        ans[i] = (ans[i - 2] + 2) % n;
    }
    for(int i = 3; i < n; i += 2){
        ans[i] = (ans[i - 2] + 2) % n;
    }
    for(int i = 0; i < n; i++){
        ans2[ans[i]] = i;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", ans2[i] + 1);
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