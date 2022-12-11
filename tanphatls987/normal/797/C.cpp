#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> lli;

#define X first
#define Y second

const int N=1e5+10;
const int alp=26;

const ll inf=1e16;

string s;
int n,a[N];
//int b[N];

string solve(){
    n=s.length();
    for(int i=n-1;i>=0;i--) a[i]=a[i+1]|(1<<(s[i]-'a'));
    string t,ans;
    for(int cur=0,pos=0;cur<alp;cur++){
        while (!t.empty()&&t.back()-'a'<=cur) {
            ans.push_back(t.back());
            t.pop_back();
        }
        while ((a[pos]>>cur)&1){
            if (s[pos]-'a'==cur) ans.push_back(s[pos]);
            else t.push_back(s[pos]);
            pos++;
        }
    }
    reverse(t.begin(),t.end());
    return ans+t;
}
int main(){
    cin>>s;
    cout<<solve();
}