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
    int a,b,c;
    a=b=c=0;
    rep(i,0,n){
        string s;
        cin>>s;
        if(s=="25")a++;
        else if(s=="50")b++,a--;
        else{
           if(b)b--;
           else a-=2;
           a--;
        }
        if(a<0){
           cout<<"NO"<<endl;
           return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}