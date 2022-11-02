#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<cstring>
#include<cassert>
#include<ctime>
#include<vector>
#include<list>
#include<stack>
#include<deque>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<algorithm>

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

int n, d, h;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &d, &h);
    if(d == 1 && n > 2){
        printf("-1");
        ret 0;
    }
    int delta = d - h;
    int left = n - h - 1;
    if(delta > h){
        printf("-1");
        ret 0;
    }
    if(left < delta){
        printf("-1");
        ret 0;
    }
    int fu = 2;
    int old = h;
    while(h > 0){
        printf("%d %d\n", fu - 1, fu);
        fu++;
        h--;
    }
    h = old;
    if(d == h){
        while(fu <= n){
            printf("2 %d\n", fu);
            fu++;
        }
        ret 0;
    }
    int prv = 1;
    while(delta > 0){
        printf("%d %d\n", prv, fu);
        prv = fu; fu++;
        delta--;
    }
    while(fu <= n){
        printf("1 %d\n", fu);
        fu++;
    }
    ret 0;
}