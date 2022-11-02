#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define y1 adjf

int n, k;
int a, b, c, d;
vector<char> can;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d%d%d%d%d", &n, &k, &a, &b, &c, &d);
    if(n == 4 || k < n + 1){printf("-1"); ret 0;}
    can.rs(n + 1);
    can.asg(n + 1, true);
    can[a] = can[b] = can[c] = can[d] = false;
    printf("%d %d ", a, c);
    F(i, 1, n + 1){
        if(can[i])
            printf("%d ", i);
    }
    printf("%d %d\n", d, b);
    printf("%d %d ", c, a);
    F(i, 1, n + 1){
        if(can[i])
            printf("%d ", i);
    }
    printf("%d %d", b, d);
    ret 0;
}