#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("e.inp","r",stdin)
#define OUTPUT freopen("e.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=5e5+10;

string s;
double f[N];
int wowel(char c){
    return (c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y');
}
int main(){
    cin>>s;
    int n=s.length();
    double ans=0,cur=0;
    FOR(i,1,n) f[i]=f[i-1]+1.0/i;
    FOR(i,1,(n+1)/2){
        cur+=f[n-i+1]-f[i-1];
        if (wowel(s[i-1])) ans+=cur;
        if (n-i!=i-1&&wowel(s[n-i])) ans+=cur;
    }
    printf("%.7f\n",ans);
}