#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+10;
const ll inf=3e18;
const int MOD=1e9+7;

int n,m,k,need;
vector <int> v[N];

ll f[12][70][12];
int mark[12][70][12];
ll g[12][70];


ll DP(int base,int length,int num){
    if (length==0) return (num==0);
    ll &cur=f[base][length][num];

    if (mark[base][length][num]) return cur;
    mark[base][length][num]=1;
    cur=0;
    if (num) cur+=num*DP(base,length-1,num-1);
    if (num<base) cur+=(base-num)*DP(base,length-1,num+1);
//    cout<<base<<" "<<length<<" "<<num<<" "<<cur<<'\n';
    return cur;
}

int s[70],h[10];
ll solve(ll k,ll n){
    int top=0;
    while (n){
        s[++top]=n%k;
        n/=k;
    }
//    assert(top-1<70&&k<10);
    ll ans=g[k][top-1];
    int n1=0;
    memset(h,0,sizeof(h));
    for(int i=top;i>=1;i--){
        for(int j=(i==top);j<s[i];j++) {
            if (h[j]) ans+=DP(k,i-1,n1-1);
            else ans+=DP(k,i-1,n1+1);
        }
        if (h[s[i]]) n1--;
        else n1++;
        h[s[i]]^=1;
    }
//    cout<<"=>"<<ans<<'\n';
    return ans;
}

void prepare(){
    for(int k=2;k<=10;k++)
        for(int i=1;i<70;i++) g[k][i]=g[k][i-1]+DP(k,i-1,1)*(k-1);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prepare();
    int test;
    cin>>test;
    while (test--){
        ll k,L,R;
        cin>>k>>L>>R;
        cout<<solve(k,R+1)-solve(k,L)<<'\n';
    }
}