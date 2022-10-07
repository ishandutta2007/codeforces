#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=100005;
ll n,m,k,ans;
string s;
int main() {
    cin>>m;
    cin>>s;
    n=s.size();
    s="#"+s;
    for (int i=1;i<=n;i++)
        k+=s[i]-'0';
    for (char ch='0';ch<'9' && k<m;ch++)
        for (int i=1;i<=n && k<m;i++)
    if (s[i]==ch){
        ans++;
        k+=9-(ch-'0');
    }
    cout<<ans<<endl;
    return 0;
}