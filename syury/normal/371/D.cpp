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
#define cont continue
#define brk break
#define ins insert
#define era erase

set<int> active;
vector<int> a, c;
int n, q;

int main(){
    scanf("%d", &n);
    a.rs(n); c.rs(n); c.asg(n, 0);
    F(i, 0, n){
        scanf("%d", &a[i]);
        active.ins(i);
    }
    scanf("%d", &q);
    F(i, 0, q){
        int type, pos;
        scanf("%d%d", &type, &pos);
        pos--;
        if(type == 1){
            int add;
            scanf("%d", &add);
            while(add > 0){
                auto it = active.lower_bound(pos);
                if(it == active.end())
                    brk;
                int j = *it;
                c[j] += add;
                if(c[j] > a[j]){
                    add = c[j] - a[j];
                    c[j] = a[j];
                    active.era(it);
                }
                else
                    add = 0;
            }
        }
        else{
            printf("%d\n", c[pos]);
        }
    }
    ret 0;
}