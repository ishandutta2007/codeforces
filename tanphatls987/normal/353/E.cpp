#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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

int main(){
    string s;
    cin>>s;
    int n=s.length(),ans1=0,c=0;
    while (s.back()==s.front()) s.pop_back(),c++;
    s.insert(0,c,s[0]);
//    cout<<s;
    c=0;
    REP(i,0,n){
        int j=i;
        while (i<n&&s[i+1]==s[i]) i++;
        if (!c) {
            ans1++;
            if (i==j) c=-1;
        }else c=0;
//        printf("%d %d %d %d\n",j,i,ans1,c);
    }
    ans1+=c;
    c=0;
    int st=0,ans2=0;
    while (s[st]==s[0]) st++;
    REP(i,st,n){
        int j=i;
        while (i<n&&s[i+1]==s[i]) i++;
//        printf("%d %d %d\n",j,i,ans);
        if (!c) {
            ans2++;
            if (i==j) c=-1;
        }else c=0;
    }
//    cout<<ans1<<" "<<ans2<<'\n';
    cout<<max(ans1,ans2);
}