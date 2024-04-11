#include<cstdio>
#include<algorithm>
using namespace std;
int l[100001];
int e[100001];
int n, m, cl, ce, v;
int get(int a, int b, int x, int y){
    if(a==x) return abs(b-y);
    x = abs(x-a);
    if(b > y) swap(b, y);

    if(lower_bound(e+1, e+ce+1, b) != lower_bound(e+1, e+ce+1, y)){
        return y-b + (x/v) + (x%v==0?0:1);
    }
    int ans=1000000000, t;

    int *p = lower_bound(e+1, e+ce+1, b); p--;
    if(p != e){
        t = y-b + 2*(b-(*p)) + (x/v) + (x%v==0?0:1);
        if(ans > t) ans = t;
    }
    
    p = lower_bound(e+1, e+ce+1, y);
    if(p != e+ce+1){
        t = y-b + 2*((*p)-y) + (x/v) + (x%v==0?0:1);
        if(ans > t) ans = t;
    }

    int *l1, *l2;
    l1 = lower_bound(l+1, l+cl+1, b);
    l2 = lower_bound(l+1, l+cl+1, y);
    if(l1 == l2){
        if(l1 != l+1){
            l1--;
            t = y-b + x + 2*(b-(*l1));
            if(ans > t) ans = t;
        }
        if(l2 != l+cl+1){
            t = y-b + x + 2*((*l2)-y);
            if(ans > t) ans = t;
        }
    } else{
        t = y-b + x;
        if(ans > t) ans = t;
    }
    return ans;
}
int main(){
    scanf("%d%d%d%d%d", &n,&m, &cl, &ce, &v);
    int q;
    for(int i=1; i<=cl; i++)scanf("%d", l+i);
    for(int i=1; i<=ce; i++)scanf("%d", e+i);
    scanf("%d", &q);
    for(int i=1; i<=q; i++){
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        printf("%d\n", get(a, b, x, y));
    }
    return 0;
}