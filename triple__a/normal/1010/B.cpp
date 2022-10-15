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

int n,k;
bool vis[37];
int cnt=0;
bool check(int u){
    cout<<u<<endl;
    int w;
    cin>>w;
    if (!w) exit(0);
    return w>0;
}

bool ms(int l,int r){
    int md=(l+r)>>1;
    if (check(md)^vis[(cnt++)%k]^1) return ms(md+1,r);
    else return ms(l,md);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for (int i=0;i<k;++i){
        vis[i]=check(1);
    }
    ms(1,n);
    return 0;
}