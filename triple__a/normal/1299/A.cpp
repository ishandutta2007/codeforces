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

const int maxn=200007;
int n,k;
int a[maxn];

int calc(int u){
    vector<int> vec;
    vec.clear();
    for (int i=1;i<=n;++i){
        if (a[i]>>u&1) vec.pb(i); 
    }
    if (vec.size()==1) return vec[0];
    else return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=30;i>-1;--i){
        int ret=calc(i);
        if (ret>-1){
            cout<<a[ret]<<" ";
            for (int i=1;i<=n;++i){
                if (i==ret) continue;
                cout<<a[i]<<" ";
            }
            return 0;
        }
    }
    for (int i=1;i<=n;++i){
        cout<<a[i]<<" ";
    }
    return 0;
}