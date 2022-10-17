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
    int n;
    cin>>n;
    set<pii> v;
    rep(i,0,n){
        int s,d;
        cin>>s>>d;
        bool b=1;
        for(pii t:v){
            //cout<<s<<" "<<s+d<<" "<<t.X<<" "<<t.Y<<endl;
            if(t.X<s+d && s<t.Y) b=0;
        }
        pii q;
        if(b) q=pii(s,s+d);
        else{
            int lx=1;
            for(pii t:v){
                if(lx+d<=t.X){
                    q=pii(lx,lx+d);
                    lx=0;
                    break;
                }
                lx = t.Y;
            }
            if(lx) q=pii(lx,lx+d);
        }
        v.insert(q);
        cout<<q.X<<" "<<q.Y-1<<endl;
    }
    return 0;
}