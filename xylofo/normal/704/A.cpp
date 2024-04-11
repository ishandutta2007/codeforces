#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    int cnt = 0,t=0;
    vi v(n+5,0);
    vi s(1,-1);
    rep(i,0,q){
        int a,x;
        cin>>a>>x;
        if(a==1){
           s.push_back(v[x]);
           v[x]=s.size()-1;
           cnt++;
        }
        if(a==2){
            x = v[x];
            while(s[x]!=-1){
                int t = s[x];
                s[x]=-1;
                x=t;
                cnt--;
            }
        }
        if(a==3){
            while(t<x) {
                if(s[++t]+1)cnt--;
                s[t]=-1;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}