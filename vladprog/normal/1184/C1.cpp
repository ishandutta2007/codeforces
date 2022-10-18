#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

const int N = 100+1, inf = 1e7+1;

int n;
pair<int, int> a[N];
int minx, minxcnt, maxx, maxxcnt, miny, minycnt, maxy, maxycnt;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    n = 4*n+1;
    minx = inf;
    maxx = -inf;
    miny = inf;
    maxy = -inf;
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        if(x < minx){
            minx = x;
            minxcnt = 0;
        }
        if(x == minx)
            ++minxcnt;

        if(x > maxx){
            maxx = x;
            maxxcnt = 0;
        }
        if(x == maxx)
            ++maxxcnt;

        if(y < miny){
            miny = y;
            minycnt = 0;
        }
        if(y == miny)
            ++minycnt;

        if(y > maxy){
            maxy = y;
            maxycnt = 0;
        }
        if(y == maxy)
            ++maxycnt;
    }
    if(minxcnt == 1)
        for(int i = 0; i < n; ++i)
            if(a[i].x == minx){
                cout << a[i].x << ' ' << a[i].y << '\n';
                return 0;
            }
    if(maxxcnt == 1)
        for(int i = 0; i < n; ++i)
            if(a[i].x == maxx){
                cout << a[i].x << ' ' << a[i].y << '\n';
                return 0;
            }
    if(minycnt == 1)
        for(int i = 0; i < n; ++i)
            if(a[i].y == miny){
                cout << a[i].x << ' ' << a[i].y << '\n';
                return 0;
            }
    if(maxycnt == 1)
        for(int i = 0; i < n; ++i)
            if(a[i].y == maxy){
                cout << a[i].x << ' ' << a[i].y << '\n';
                return 0;
            }
    for(int i = 0; i < n; ++i)
        if(a[i].x != minx && a[i].x != maxx && a[i].y != miny && a[i].y != maxy){
            cout << a[i].x << ' ' << a[i].y << '\n';
            return 0;
        }
    exit(1);
}