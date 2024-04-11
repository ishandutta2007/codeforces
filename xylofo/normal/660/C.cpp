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
    int n,k;
    cin>>n>>k;
    vi v(n),w(n);
    if(k==0){
        int mx=0;
        int st=0;
        rep(i,0,n){
            cin>>v[i];
            if(v[i]==0)st=i+1;
            mx=max(mx,i-st+1);
        }
        cout<<mx<<endl;
        rep(i,0,n)cout<<v[i]<<" ";
        return 0;
    }
    pii bst={0,0};
    int t=0,st=0;
    rep(i,0,n){
        cin>>v[i];
        if(v[i]==0)t++;
        if(t>k){
            while(v[st]==1)st++;
            w[st++]=0;
            t--;
        }
        bst=max(bst,mp(i-st+1,st));
    }
    cout<<bst.X<<endl;
    t=0;
    rep(i,0,n){
        if(i<bst.Y || t==k) cout<<v[i]<<" ";
        else{
            cout<<1<<" ";
            t+=1-v[i];
        }
    }
    return 0;
}