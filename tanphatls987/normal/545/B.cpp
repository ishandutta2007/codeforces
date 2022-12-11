#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

string s1,s2;
int main(){
    cin>>s1>>s2;
    int n=s1.length(),c=0;
    REP(i,0,n) c+=(s1[i]!=s2[i]);
    if (c%2) printf("impossible");
    else {
        for(int i=0,c1=0;i<n;i++) if (s1[i]!=s2[i]){
            c1++;
            if (c1*2>c) s1[i]=s2[i];
        }
        cout<<s1;
    }
}