#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int seg[1<<18];
int n, m;
void upd(int p,int b) {
    p+=1<<n;
    seg[p] = b;
    bool t= 1;
    while(p>1) {
        p/=2;
        if(t) seg[p] = seg[2*p]|seg[2*p+1];
        else seg[p] = seg[2*p]^seg[2*p+1];
        t = 1-t;
    }
}
int main() {
    cin >> n >> m;
    for(int i=0;i<1<<n;i++) {
        int x; cin >> x;
        upd(i,x);
    }
    while(m--) {
        int p,b; cin >> p >> b;
        --p;
        upd(p,b);
        cout << seg[1] << endl;
    }
}