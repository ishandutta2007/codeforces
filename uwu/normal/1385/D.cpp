#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=(1<<17)+1;

int arr[MAXN][18],n;
map<int,int> lg2;
string uwu;

int solve(int idx, int len){
    if (len==-1) return uwu[idx]!='a'+lg2[n];
    return min(solve(idx,len-1)+arr[idx+(1<<len)][len],solve(idx+(1<<len),len-1)+arr[idx][len]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i=0;i<=17;++i) lg2[1<<i]=i;
    while (t--){
        cin >> n;
        cin >> uwu; uwu=" "+uwu;
        char a='a'+lg2[n]-1; int cnt;
        for (int len=0;len<lg2[n];++len,--a){
            for (int i=1;i<=n;i+=(1<<len)){
                cnt=0;
                for (int j=i;j<i+(1<<len);++j) cnt+=uwu[j]!=a;
                arr[i][len]=cnt;
                //cout << i << " " << a << " " << len << " " << cnt << '\n';
            }
        }
        cout << solve(1,lg2[n]-1) << '\n';
    }
}