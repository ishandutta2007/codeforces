#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;

#define X first
#define Y second

const int N=1e5+10;
const int maxv=1e6+10;
const string wowel="aeiou";

int n;
string s[N];
ii ans[N];

map <int,int> ma[10];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++)
        for(int st=0;st<9;st++)
            for(int val=0,en=st;en<9;en++){
                val=10*val+s[i][en]-'0';
                ma[en-st][val]++;
            }
    for(int i=1;i<=n;i++) ans[i]=ii(0,10);
    for(int i=1;i<=n;i++){
        for(int st=0;st<9;st++)
            for(int val=0,en=st;en<9;en++){
                val=10*val+s[i][en]-'0';
                ma[en-st][val]--;
            }
        for(int st=0;st<9;st++)
            for(int val=0,en=st;en<9;en++){
                val=10*val+s[i][en]-'0';
                if (!ma[en-st][val]&&en-st<ans[i].Y-ans[i].X) ans[i]=ii(st,en);
                ma[en-st][val]++;
            }
    }
//    for(int i=1;i<=n;i++) cout<<ans[i].X<<" "<<ans[i].Y<<'\n';
    for(int i=1;i<=n;i++) cout<<s[i].substr(ans[i].X,ans[i].Y-ans[i].X+1)<<'\n';
}