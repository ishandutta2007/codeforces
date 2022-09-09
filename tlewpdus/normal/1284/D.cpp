#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int SQ = 700;

int n;
bitset<100001> buc[4][SQ];
int arr[100100][4];
vector<int> comp[4];
int ord[4][100100];
int loc[100100][4];
bitset<100001> ra;
int main() {
    scanf("%d",&n);
    //n = 100000;
    for (int i=0;i<n;i++) {
        for (int j=0;j<4;j++) {
            scanf("%d",&arr[i][j]);
            //arr[i][j] = i+j;
            comp[j].push_back(arr[i][j]);
        }
    }
    for (int i=0;i<4;i++) {
        iota(ord[i],ord[i]+n,0);
        sort(ord[i],ord[i]+n,[&i](int a, int b){return arr[a][i]<arr[b][i];});
        for (int j=0;j<n;j++) loc[ord[i][j]][i] = j;
    }
    for (int j=0;j<4;j++) sort(comp[j].begin(),comp[j].end());
    for (int i=0;i<n;i++) {
        for (int j=0;j<4;j++) {
            buc[j][loc[i][j]/SQ].set(i);
        }
    }
    for (int j=0;j<4;j++) {
        if (j%2==1){
            for (int i=1;i<=(n-1)/SQ;i++) buc[j][i]^=buc[j][i-1];
        }
        else {
            for (int i=(n-1)/SQ-1;i>=0;i--) buc[j][i]^=buc[j][i+1];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<4;j++) {
            int v = ((j%2==0)?lower_bound(comp[j^1].begin(),comp[j^1].end(),arr[i][j])-comp[j^1].begin()-1:
                            upper_bound(comp[j^1].begin(),comp[j^1].end(),arr[i][j])-comp[j^1].begin());
            if (j%2==0) {
                if (v/SQ) ra ^= buc[j^1][v/SQ-1];
                for (int k=v/SQ*SQ;k<=v;k++) ra.flip(ord[j^1][k]);
            }
            else {
                if (v/SQ<(n-1)/SQ) ra ^= buc[j^1][v/SQ+1];
                for (int k=v;k<v/SQ*SQ+SQ&&k<n;k++) ra.flip(ord[j^1][k]);
            }
        }
        if (ra.any()) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");

	return 0;
}