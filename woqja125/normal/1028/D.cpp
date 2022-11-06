#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
char tmp[100];
int in[370000][2];
int base;
int IT[1100000];
const int MOD = 1000000007;
void add(int x, int v) {
    x += base;
    do{
        IT[x]+=v;
    } while(x/=2);
}
int getsum(int f, int r) {
    int re = 0;
    f += base; r += base;
    while(f<=r) {
        if(f%2 == 1) re += IT[f++];
        if(r%2 == 0) re += IT[r--];
        f/=2; r/=2;
    }
    return re;
}
int find(int s) {
    int x = 1;
    while(x < base) {
        if(IT[x*2] >= s) x = x*2;
        else {
            s -= IT[x*2];
            x = x*2+1;
        }
    }
    return x - base;
}
int main() {
    int n, p;
    scanf("%d", &n);
    vector<int> P;
    P.push_back(0);
    P.push_back(310000000);
    for(int i=1; i<=n; i++) {
        scanf("%s%d", tmp, &in[i][1]);
        if(tmp[1] == 'D') in[i][0] = 1;
        else in[i][0] = 2;
        P.emplace_back(in[i][1]);
    }
    sort(P.begin(), P.end());
    int m=0, M=P.size()-1, ans = 1;
    for(base=1; base <= P.size(); base <<= 1);
    add(0, 1);
    add(P.size()-1, 1);
    for(int i=1; i<=n; i++) {
        p = lower_bound(P.begin(), P.end(), in[i][1]) - P.begin();
        if(in[i][0] == 1){
            add(p, 1);
        }
        else if(in[i][0] == 2) {
            if(m <= p && p <= M) {
                if(p!=m && p!=M) ans = ans*2ll%MOD;
                int s = getsum(0, p);
                m = find(s-1);
                M = find(s+1);
                add(p, -1);
            }
            else {
                printf("0\n");
                return 0;
            }
        }
        //printf("#%d %d\n", m, M);
    }
    int remain = getsum(m+1, M-1);
    ans = 1ll*ans*(remain+1)%MOD;
    printf("%d\n", ans);
    return 0;
}