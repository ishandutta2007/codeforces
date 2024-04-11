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
string s;
int q;
int ans[maxn][27];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>s>>q;
    int n=s.size();
    for (int i=0;i<n;++i){
        for (int j=0;j<26;++j){
            ans[i+1][j]=ans[i][j];
        }
        ans[i+1][s[i]-'a']++;
    }
    while (q--){
        int l,r;
        cin>>l>>r;
        if (l==r){
            cout<<"Yes\n";
            continue;
        }
        if (s[l-1]!=s[r-1]){
            cout<<"Yes\n";
            continue;
        }
        int t=0;
        for (int j=0;j<26;++j){
            if (ans[r][j]>ans[l-1][j]) t++;
        }
        if (t>2) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}