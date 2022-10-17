#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200005];
ll sum[200005];
int main()
{
    ll n,s;
    cin>>n>>s;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
    int mid = n/2+1;
    if(a[mid] == s) return cout<<0<<endl,0;
    int pos = lower_bound(a+1,a+1+n,s)-a;
    if(pos <= mid) cout << (sum[mid]-sum[pos-1])-s*(mid-pos+1) << endl;
    else cout << s*(pos-mid)- (sum[pos-1]-sum[mid-1]) << endl;
}