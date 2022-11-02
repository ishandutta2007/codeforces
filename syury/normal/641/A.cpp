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

using namespace std;
typedef long long lint;
typedef long double ldb;

int n;
string s;
vector<int> rng;
vector<char> bad;
vector<char> was;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rng.rs(n); bad.rs(n);
    bad.asg(n, false);
    was.rs(n); was.asg(n, false);
    cin >> s;
    F(i, 0, n){
        cin >> rng[i];
        int d = (s[i] == '>') ? 1 : (-1);
        d *= rng[i];
        d += i;
        if(d < 0 || d >= n){bad[i] = true;}
    }
    int v = 0;
    while(!bad[v] && !was[v]){
        was[v] = true;
        int d = (s[v] == '>') ? 1 : (-1);
        d *= rng[v];
        v += d;
    }
    if(bad[v])
        printf("FINITE");
    else
        printf("INFINITE");
    ret 0;
}