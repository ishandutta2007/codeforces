#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

struct Point{
    int x, y;
};
vector<Point> one, two;

void place(Point a, int c){
    cout << c << " " << a.x << " " << a.y << '\n';
    cout.flush();
}

void owo(int c){
    Point x=one.back(); one.pop_back();
    place(x,c);
}

void uwu(int c){
    Point x=two.back(); two.pop_back();
    place(x,c);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if ((i+j)%2==0) one.push_back({i,j});
            else two.push_back({i,j});
        }
    }
    int x;
    for (int i=1;i<=n*n;++i){
        cin >> x;
        if (!one.empty()&&!two.empty()){
            if (x==1) uwu(2);
            else owo(1);
        }
        else{
            if (!one.empty()){
                if (x==1||x==2) owo(3);
                else owo(1);
            }
            else{
                if (x==1||x==3) uwu(2);
                else uwu(3);
            }
        }
    }
}