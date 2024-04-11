#include<cstdio>
#include<algorithm>
#include<vector>
struct P{
    long long x, y;
    int i;
    bool operator<(const P &A) const {
        return x*x+y*y < A.x*A.x+A.y*A.y;
    }
};
std::vector<P> d;
bool chk(long long x, long long y) {
    if(x > 1500000 || y > 1500000) return false;
    if(x*x+y*y > 1500000ll*1500000) return false;
    return true;
}
int re[100001];
int main() {
    int n, i;
    long long x, y, u, v, a, b;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld%lld", &x, &y);
        d.push_back({x, y, i});
    }
    std::sort(d.begin(), d.end());
    if(n%2 == 0){
        a = b = 0;
        i = 0;
    }
    else {
        a = d[0].x; b = d[0].y;
        re[d[0].i] = 1;
        i = 1;
    }
    for(; i<n; i+=2) {
        x = d[i].x; y = d[i].y;
        u = d[i+1].x; v = d[i+1].y;
        if(chk(a+x+u, b+y+v)) {
            a += x+u; b += y+v;
            re[d[i].i] = re[d[i+1].i] = 1;
        }
        else if(chk(a+x-u, b+y-v)) {
            a += x-u; b += y-v;
            re[d[i].i] = -(re[d[i+1].i] = -1);
        }
        else if(chk(a-x+u, b-y+v)) {
            a -= x-u; b -= y-v;
            re[d[i].i] = -(re[d[i+1].i] = 1);
        }
        else {
            a -= x+u; b -= y+v;
            re[d[i].i] = re[d[i+1].i] = -1;
        }
    }
    for(int i=1; i<=n; i++) printf("%d ", re[i]);
    printf("\n");
    return 0;
}