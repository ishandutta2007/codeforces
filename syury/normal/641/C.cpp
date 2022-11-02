#include<bits/stdc++.h>

#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define rs resize
#define asg assign
#define mk make_pair
#define all(x) x.begin(),x.end()
#define pb push_back
#define ret return
#define X first
#define Y second
#define ins insert
#define era erase
#define beg begin
#define cont continue
#define brk break

using namespace std;
typedef long long lint;
typedef long double ldb;

int n, q;
lint td = 0, od = 0;
vector<int> w;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d", &n, &q);
    w.rs(n);
    F(i, 0, q){
        int type, d;
        scanf("%d", &type);
        if(type == 1){
            scanf("%d", &d);
            td += d;
            cont;
        }
        if((td + od) % 2 == 0)
            od++;
        else
            od--;
    }
    F(i, 0, n){
        lint pos = i + 1;
        if(i%2 == 0){
            pos += od;
        }
        else{
            pos -= od;
        }
        pos += td;
        pos = (pos % n + n) % n;
        w[(pos - 1 + n)%n] = i + 1;
    }
    F(i, 0, n)
        printf("%d ", w[i]);
    ret 0;
}