#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=1e5+10,M=26;
const int mod=1e7+7;
 
int pre[N];
char s[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    int n,q;cin>>n>>q;
    cin>>s+1;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+(s[i]-'a'+1);
    }
    while(q--){
        int l,r;cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<'\n';
    }
}