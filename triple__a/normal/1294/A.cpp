#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long t,a,b,c,n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>a>>b>>c>>n;
        if ((a+b+c+n)%3){
            puts("NO");
            continue;
        }
        long long u=(a+b+c+n)/3;
        if (a>u||b>u||c>u) puts("NO");
        else puts("YES");
    }
    return 0;
}