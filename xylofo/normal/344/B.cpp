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
    int a,b,c;
    cin>>a>>b>>c;
    if((a+b+c)%2 || a>b+c || b>a+c || c>a+b)
        cout<<"Impossible"<<endl;
    else {
        cout<<(a+b-c)/2<<" "<<(-a+b+c)/2<<" "<<(a-b+c)/2<<endl;
    }
    return 0;
}