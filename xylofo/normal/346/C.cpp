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

unsigned int v[1010101];

int nxt(int x, int y){ //next multiple of x which is larger than y
    return ((y-1)/x+1)*x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(v,-1,sizeof(v));
    int n,a,b;
    cin>>n;
    vi x(n);
    rep(i,0,n) cin>>x[i]; 
    sort(allof(x));
    x.resize(unique(allof(x))-x.begin());
    cin>>a>>b;
    set<pii> s;
    rep(i,0,n) s.insert({nxt(x[i],b),x[i]});
    v[0]=b;
    rep(i,b+1,a+1){
        while(s.begin()->X+s.begin()->Y<=i){
            int x=s.begin()->Y;
            s.erase(s.begin());
            s.insert({nxt(x,i-x+1),x});
            //if(x==5)cout<<nxt(x,i)<<" "<<i<<endl;
        }
        //if(i>=225 && i<=235)cout<<":"<<i<<" "<<s.begin()->X<<endl;
        v[i-b] = min(i-1,s.begin()->X);
    }
    //rep(i,b,a+1){
        //cout<<i<<" "<<v[i-b]<<endl;
    //}
    int ans=0;
    //cout<<a<<endl;
    while(a!=b) {
        //bool bo=v[a-b]==a-1;
        //rep(i,0,n)if(v[a-b]==a-(a%x[i]))bo=true;
        //rep(i,0,n)if(v[a-b]>a-(a%x[i]))cout<<"What "<<x[i]<<endl;
        a=v[a-b],ans++;
        //if(bo==false) cout<<"HEYYY"<<endl;
        //cout<<a<<endl;
    }
    //cout<<endl;
    cout<<ans<<endl;
    return 0;
}