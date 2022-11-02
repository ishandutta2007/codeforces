//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = 1111;

int h, w, k;
int col[N][N];
bool eq1[N][N];
bool eq2[N][N];

void solve(){
    bool need_transpose = false;
    cin >> h >> w >> k;
    if(k > 1 && (w - 1)*h < (h - 1)*w)
        need_transpose = true;
    for(int i = 0; i < h; i++){
        string hor;
        cin >> hor;
        for(int j = 0; j < w - 1; j++)
            eq1[i][j] = hor[j] == 'E';
        if(i != h - 1){
            string vert;
            cin >> vert;
            for(int j = 0; j < w; j++)
                eq2[i][j] = vert[j] == 'E';
        }
    }
    if(k == 1){
        int ok = 0;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                ok += int(eq1[i][j]) + int(eq2[i][j]);
        int total = (w - 1) * h + w * (h - 1);
        if(4*ok >= 3*total){
            cout << "YES\n";
            for(int i = 0; i < h; i++)
                for(int j = 0; j < w; j++)
                    cout << 1 << " \n"[j + 1 == w];
        }
        else
            cout << "NO\n";
        return;
    }
    if(need_transpose){
        bool tmp1[N][N], tmp2[N][N];
        memset(tmp1, 0, sizeof(tmp1));
        memset(tmp2, 0, sizeof(tmp2));
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++){
                tmp2[j][i] = eq1[i][j];
                tmp1[j][i] = eq2[i][j];
            }
        memset(eq1, 0, sizeof(eq1));
        memset(eq2, 0, sizeof(eq2));
        for(int i = 0; i < w; i++)
            for(int j = 0; j < h; j++){
                eq1[i][j] = tmp1[i][j];
                eq2[i][j] = tmp2[i][j];
            }
        swap(h, w);
    }
    for(int i = 0; i < h; i++){
        col[i][0] = 0;
        for(int j = 1; j < w; j++){
            col[i][j] = eq1[i][j - 1] ? col[i][j - 1] : (1^col[i][j - 1]);
        }
        if(i){
            int good = 0, bad = 0;
            for(int j = 0; j < w; j++){
                if(eq2[i - 1][j] && col[i - 1][j] == col[i][j])++good;
                else if(!eq2[i - 1][j] && col[i - 1][j] != col[i][j])++good;
                else ++bad;
            }
            if(good < bad){
                for(int j = 0; j < w; j++)
                    col[i][j] ^= 1;
            }
        }
    }
    if(need_transpose){
        int tmp[N][N];
        memset(tmp, 0, sizeof(tmp));
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                tmp[j][i] = col[i][j];
        swap(h, w);
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                col[i][j] = tmp[i][j];
    }
    cout << "YES\n";
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << 1 + col[i][j] << " \n"[j + 1 == w];
        }
    }
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}