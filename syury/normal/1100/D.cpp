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
typedef double dbl;
typedef pair<int, int> pii;

const int n = 999, m = 666;

int f[n][n];
pii pos[m];
int my_x, my_y;

void make_move(int dx, int dy){
    int k, x, y;
#ifdef LOCAL
    my_x += dx;
    my_y += dy;
    bool fuck = 0;
    for(int i = 0; i < m; i++){
        if(pos[i].X == my_x || pos[i].Y == my_y)
            fuck = 1;
    }
    k = x = y = -1;
    int dk = 0, df = 0;
    if(!fuck){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int d = min(abs(i - my_x), abs(j - my_y));
                if(f[i][j] != -1 && (k == -1 || d < dk)){
                    dk = d;
                    k = f[i][j];
                }
                if(f[i][j] == -1 && (x == -1 || d > df)){
                    df = d;
                    x = i; y = j;
                }
            }
        }
        ++k; ++x; ++y;
    }
#else
    cout << my_x + dx + 1 << ' ' << my_y + dy + 1 << endl;
    cin >> k >> x >> y;
    if(k == 0)
        exit(0);
#endif
    my_x += dx;
    my_y += dy;
    if(k == -1)
        exit(0);
    --k;
    --x; --y;
    f[pos[k].X][pos[k].Y] = -1;
    pos[k] = {x, y};
    f[x][y] = k;
}

void mv(int dx, int dy){
    int x = my_x + dx, y = my_y + dy;
    if(f[x][y] != -1){
        if(dx != 0)
            make_move(dx, 0);
        else
            make_move(0, dy);
    }
    else
        make_move(dx, dy);
}

void solve(){
#ifdef LOCAL
    srand(time(0));
    my_x = rand()%n;
    my_y = rand()%n;
#else
    cin >> my_x >> my_y;
    --my_x; --my_y;
#endif
    for(int i = 0; i < n; i++)
        fill(f[i], f[i] + n, -1);
    for(int i = 0; i < m; i++){
#ifdef LOCAL
        do{
            pos[i].X = rand()%n;
            pos[i].Y = rand()%n;
        }while((pos[i] == make_pair(my_x, my_y)) || (f[pos[i].X][pos[i].Y] != -1));
#else
        cin >> pos[i].X >> pos[i].Y;
        --pos[i].X; --pos[i].Y;
#endif
        f[pos[i].X][pos[i].Y] = i;
    }
    while(my_x < n/2){
        mv(1, 0);
    }
    while(my_x > n/2){
        mv(-1, 0);
    }
    while(my_y < n/2){
        mv(0, 1);
    }
    while(my_y > n/2){
        mv(0, -1);
    }
    int c[4] = {0, 0, 0, 0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(f[i][j] == -1)continue;
            if(i < n/2 && j < n/2)
                ++c[0];
            if(i < n/2 && j > n/2)
                ++c[1];
            if(i > n/2 && j < n/2)
                ++c[2];
            if(i > n/2 && j > n/2)
                ++c[3];
        }
    }
    int fail = min_element(c, c + 4) - c;
    int dx, dy;
    switch(fail){
        case 0:
            dx = dy = 1;
            break;
        case 1:
            dx = 1; dy = -1;
            break;
        case 2:
            dx = -1; dy = 1;
            break;
        case 3:
            dx = dy = -1;
            break;
    }
    for(int i = 0; i < (n - 1)/2; i++){
        mv(dx, dy);
    }
    assert(false);
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