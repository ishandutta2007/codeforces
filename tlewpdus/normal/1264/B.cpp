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

int a, b, c, d;

void pung(){
    puts("NO");
    exit(0);
}

int main() {
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if (b<a-1||c<d-1) pung();
    if (b==a-1) {
        if (c||d) pung();
        puts("YES");
        for (int i=0;i<b;i++) printf("0 1 ");
        puts("0");
        return 0;
    }
    if (c==d-1) {
        if (a||b) pung();
        puts("YES");
        for (int i=0;i<c;i++) printf("3 2 ");
        puts("3");
        return 0;
    }
    for (int tcur=0;tcur<4;tcur++) {
        int arr[4] = {a,b,c,d};
        int cur=tcur,bad = 0;
        vector<int> ans;
        for(int i=0;i<a+b+c+d;i++) {
            if (cur>=4) {
                bad = 1;
                break;
            }
            ans.push_back(cur); arr[cur]--;
            if (cur==0) {
                cur++;
            }
            else if (arr[cur-1]) {
                cur--;
            }
            else cur++;
        }
        for (int i=0;i<4;i++) {
            if (arr[i]) bad = 1;
        }
        if (!bad) {
            puts("YES");
            for (int &v : ans) printf("%d ",v); puts("");
            return 0;
        }
    }
    pung();

	return 0;
}