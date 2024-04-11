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

map<char,int> ANS;

int n;
vector<vector<int> > save;
int ask(int a,int b){
    if(save[a][b]!=2) return save[a][b];
    cout<<"? "<<a<<" "<<b<<endl;
    char c;
    cin>>c;
    return save[a][b] = ANS[c];
}

int T;

int main(){
    ANS['<'] = 1;
    ANS['>'] = -1;
    ANS['='] = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        save.assign(n+1,vi(n+1,2));
        vi a,b;
        for(int i=1;i<=n;i+=2){
            if(i==n) {a.pb(i),b.pb(i); break;}
            if(ask(i,i+1) == 1) a.pb(i),  b.pb(i+1);
            else                a.pb(i+1),b.pb(i);
        }
        int A=a[0];
        rep(i,1,a.size()) if(ask(a[i],A)==1)A=a[i];
        int B=b[0];
        rep(i,1,b.size()) if(ask(b[i],B)==-1)B=b[i];
        cout<<"! "<<A<<" "<<B<<endl;
    }
    return 0;
}