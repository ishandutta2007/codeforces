#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define LL long long int
#define INF 2000000005
#define maxn 250005
using namespace std;
int tail[32][maxn];
int head[32][maxn];
int two[32];
int line[maxn];
int L[maxn];
int R[maxn];
int n;

int mx[maxn << 2];
int qx, qy, qd;

void pushup(int l, int r, int o){
    if (line[mx[o << 1]] == line[mx[o << 1 | 1]]) mx[o] = mx[o << 1 | 1];
    else mx[o] = (line[mx[o << 1]] > line[mx[o << 1 | 1]]) ? mx[o << 1] : mx[o << 1 | 1];
}

void init(int l, int r, int o){
    if (l == r){
        mx[o] = l;
        return;
    }
    int mid = ((r - l) >> 1) + l;
    init(l, mid, o << 1);
    init(mid + 1, r, o << 1 | 1);
    pushup(l, r, o);
}

int get(int l, int r, int o){
    if (qx <= l && r <= qy){
        return mx[o];
    }
    int mid = ((r - l) >> 1) + l;
    int ans = 0;
    if (qx <= mid) ans = get(l, mid, o << 1);
    if (qy > mid){
        int d = get(mid + 1, r, o << 1 | 1);
        if (line[d] == line[ans]) ans = d;
        else ans = (line[ans] > line[d]) ? ans : d;
    }
    return ans;
}

LL ans = 0;

void DAC(int l, int r){
    if (l >= r) return;
    qx = l, qy = r;
    int pos = get(1, n, 1);
    int _l = max(l - 1, L[pos]);
    int _r = min(r + 1, R[pos]);
    ans += (LL)(pos - l + 1) * (r - pos + 1) - (LL)(pos - _l) * (_r - pos);
    DAC(l, pos - 1);
    DAC(pos + 1, r);
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &line[i]);
    init(1, n, 1);
    two[0] = 1;
    for (int j = 1; j < 31; j++) two[j] = two[j - 1] << 1;
    for (int j = 0; j < 31; j++) tail[j][n + 1] = n + 1;
    for (int i = n; i >= 1; i--){
        for (int j = 0; j < 31; j++){
            //save[j][i] += save[j][i - 1];
            if (!tail[j][i]) tail[j][i] = tail[j][i + 1];
            if (line[i] & two[j]){
                //save[j][i]++;
                tail[j][i - 1] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 31; j++){
            //save[j][i] += save[j][i - 1];
            if (!head[j][i]) head[j][i] = head[j][i - 1];
            if (line[i] & two[j]){
                //save[j][i]++;
                head[j][i + 1] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        R[i] = INF;
        for (int j = 0; j < 31; j++){
            if (!(line[i] & two[j])){
                L[i] = max(L[i], head[j][i]);
                R[i] = min(R[i], tail[j][i]);
            }
        }
    }
    DAC(1, n);
    printf("%I64d", ans);
    return 0;
}