#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string a1,b1;cin>>a1>>b1;
    int sum1=0;int a[n];for(int i=0;i<n;++i) {a[i]=a1[i]-'0';if(i%2==0) sum1+=a[i]; else sum1-=a[i];}
    int sum2=0;int b[n];for(int i=0;i<n;++i) {b[i]=b1[i]-'0';if(i%2==0) sum2+=b[i]; else sum2-=b[i];}
    if(sum1!=sum2) {cout<<(-1);return 0;}
    int a2[n];for(int i=0;i<n;++i) a2[i]=a[i];
    int b2[n];for(int i=0;i<n;++i) b2[i]=b[i];
    int c[n]={0};
    int ans=0;
    for(int i=0;i<n-1;++i)
    {
        c[i]=b2[i]-a2[i];
        ans+=abs(c[i]);
        a2[i]+=c[i];a2[i+1]+=c[i];//overflow???
    }
    cout<<ans<<endl;
    vector <pair<int,int> > res;
    int pos=0;
    while(pos<n-1 && res.size()<1e5)
    {
        if(c[pos]==0) {++pos;continue;}
        if(c[pos]>0) {if(a[pos]<9 && a[pos+1]<9) {res.push_back({pos,1});a[pos]++;a[pos+1]++;c[pos]--;pos--;pos=max(pos,0LL);} else {++pos;}}
        else {if((a[pos]>1 || (pos!=0 && a[pos]>0)) && a[pos+1]>0) {res.push_back({pos,-1});a[pos]--;a[pos+1]--;c[pos]++;pos--;pos=max(pos,0LL);} else {++pos;}}
    }
    for(auto h:res) cout<<h.first+1<<' '<<h.second<<endl;
    return 0;
}