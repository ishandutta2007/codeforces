#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e3+5;
int fe[maxn];int fe2[maxn];
void pl(int pos,int val) {while(pos<maxn) {fe[pos]+=val;pos|=(pos+1);}}
int get(int pos) {int ans=0;while(pos>=0) {ans+=fe[pos];pos&=(pos+1);--pos;} return ans;}
void pl2(int pos,int val) {while(pos<maxn) {fe2[pos]+=val;pos|=(pos+1);}}
int get2(int pos) {int ans=0;while(pos>=0) {ans+=fe2[pos];pos&=(pos+1);--pos;} return ans;}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];for(int i=0;i<n;++i) cin>>a[i];
        int res1=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<maxn;++j) {fe[j]=0;fe2[j]=0;}
            for(int j=i+1;j<n;++j) {pl(a[j],1);}
            int res=0;
            for(int j=i+1;j<n;++j) {res-=(get2(maxn-1)-get2(a[j]));pl(a[j],-1);if(j!=(i+1)) {res+=get(a[j-1]);pl2(a[j-1],1);} if(a[j]>a[i]) res1+=res;}
        }
        for(int j=0;j<maxn;++j) {fe[j]=0;fe2[j]=0;}
        cout<<res1<<'\n';
    }
    return 0;
}