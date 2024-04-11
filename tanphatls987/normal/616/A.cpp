#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

string s1,s2;
char solve(){
    int n=s1.length(),m=s2.length();
    int L=0,R=0;
    while (L<n&&s1[L]=='0') L++;
    while (R<m&&s2[R]=='0') R++;
    int len1=n-L,len2=m-R;
    if (len1>len2) return '>';
    if (len1<len2) return '<';
    for(int i=L,j=R;i<n;i++,j++){
        if (s1[i]<s2[j]) return '<';
        if (s1[i]>s2[j]) return '>';
    }
    return '=';
}
int main(){
    cin>>s1>>s2;
    cout<<solve();

}