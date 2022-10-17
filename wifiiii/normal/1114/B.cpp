#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef long long ll;
typedef vector<int> vec;
typedef pair<ll,int> pii;

pii a[200005];
int mark[200005];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) {cin>>a[i].first;a[i].second=i;}
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    ll ans = 0;
    for(int i=1;i<=m*k;++i)
    {
        ans+=a[i].first;
        mark[a[i].second] = 1;
    }
    cout << ans << endl;
    int cnt = 0;
    vector<int> v;
    for(int i=1;i<=n;++i)
    {
        if(mark[i]) cnt++;
        if(cnt==m)
        {
            cnt = 0;
            v.pb(i);
        }
    }
    for(int i=0;i<v.size()-1;++i) cout<<v[i]<<" ";
    cout<<endl;
}