#include <bits/stdc++.h>
       
using namespace std;
       
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double
 
const int INF = (int)1e9 + 7;
 
struct tree{
    int t[500007 * 4];
    void up(int v, int vl, int vr, int pos, int val){
        if (vl == vr){
            t[v] = val;
        } else {
            int vm = (vl + vr) >> 1;
            if (vm <= pos) up(v * 2 + 1, vl, vm, pos, val);
            else up(v * 2 + 2, vm + 1, vr, pos, val);
            t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
        }
    }
 
    int get(int v, int vl, int vr, int l, int r){
        if (r < vl || l > vr) return INF;
        if (vl >= l && vr <= r) return t[v];
        int vm = (vl + vr) >> 1;
        return min(get(v * 2 + 1, vl, vm, l, r), get(v * 2 + 2, vm + 1, vr, l, r));
    }
} t;
 
struct zap{
    int l, r, val;
};
 
int n, len;
int a[500007];
int to[500007];
int need[500007];
int pred[500007];
vector<zap> q[500007];
vector<int> uk[500007];
vector<int> gg[500007];
int sp[19][500007];
int myLog[500007];
 
void stop(string s){
    cout << s;
    exit(0);
}
 
int getSp(int l, int r){
    int lvl = myLog[r - l + 1];
    return min(sp[lvl][l], sp[lvl][r - (1 << lvl) + 1]);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> len;
    for (int i = 0; i < n; i++) cin >> a[i];
 
    //reduce
 
    set<int> ss; map<int, int> mm;
    for (int i = 0; i < n; i++) ss.insert(a[i]);
    int dd = 1;
    for (int x : ss) mm[x] = dd++;
    for (int i = 0; i < n; i++) a[i] = mm[a[i]];
 
 
    //precalc
 
    set<pair<int, int> > se;
    for (int i = n - 1; i >= 0; i--){
        se.insert(mp(a[i + 1], i + 1));
        if (i + (len + 1) <= n) se.erase(mp(a[i + (len + 1)], i + (len + 1)));
        pred[i] = (*se.begin()).x;
        if ((*se.begin()).x >= a[i]) to[i] = -1;
        else {
            int now = (*se.begin()).y;
            if (se.size() > 1){
                if ((*next(se.begin())).x < a[i]) now = -2;
            }
            to[i] = now;
        }
    }  
 
    for (int i = 2; i < 500007; i++) myLog[i] = myLog[i / 2] + 1;
 
    for (int lvl = 0; lvl < 19; lvl++){
        for (int l = 0, r = (1 << lvl) - 1; r <= n; l++, r++){
            if (lvl == 0){
                sp[lvl][l] = a[l];
            } else {
                sp[lvl][l] = min(sp[lvl - 1][l], sp[lvl - 1][r - (1 << (lvl - 1)) + 1]);
            }
        }
    }
 
    //stupid part
 
    int start = -1;
    for (int i = 0; i < n; i++) if (to[i] == -1){
        start = i;
        break;
    }
    if (start == -1) stop("YES");
    int maxLast = n;
    for (int i = n - 1; i >= 0; i--) if (to[i] == -1){
        maxLast = i + 1;
        break;
    }
   
    //second part
 
    if (start + len + 1 < n){
        for (int i = 0; i < n; i++) need[i] = INF;
 
        int bad = start + 1;
        for (int i = start + len; i > start; i--){
            if (to[i] == -1){
                bad = i;
                break;
            }
        }
 
        for (int i = 0; i < n; i++) gg[i].pub(start + 1);
        for (int i = start + 2; i <= start + len; i++) if (to[i] >= 0) gg[to[i]].pub(i);
 
        for (int i = start + len + 1; i < n; i++){
            if (i >= maxLast && a[i] < a[start]){
 
                int vl = start + len, vr = n;
                while(vl + 1 < vr){
                    int vm = (vl + vr) >> 1;
                    if (getSp(start + len + 1, vm) < a[i])
                        vr = vm;
                    else
                        vl = vm;
                }
 
                int pos = vr;
                int MA = max(bad - 1, pos - len - 1);
                int last = start + len;
 
                if (MA <= last){
                    for (int j = (int)gg[i].size() - 1; j >= 0; j--){
                        if (gg[i][j] > MA){
                            q[pred[i]].pub({gg[i][j], last, need[i]});
                            need[i] = min(need[i], a[gg[i][j]]);
                            last = gg[i][j] - 1;
                        } else {
                            if (MA + 1 <= last) q[pred[i]].pub({MA + 1, last, need[i]});
                            break;
                        }
                    }
                }
            }
            if (to[i] == -1) break;
            if (to[i] != -2) need[to[i]] = min(need[to[i]], a[i]);
        }
    }
 
    for (int i = 0; i < n; i++) uk[a[i]].pub(i);
 
    for (int i = 0; i < 500007; i++){
        for (int x : uk[i]) t.up(0, 0, n - 1, x, INF);
        for (auto c : q[i]){
            if (t.get(0, 0, n - 1, c.l, c.r) < c.val) stop("YES");
        }
    }
 
 
    stop("NO");
}