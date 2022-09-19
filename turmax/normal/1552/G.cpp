#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector <int> a[k];int num[n];for(int i=0;i<n;++i) num[i]=(-1);
    for(int i=0;i<k;++i) {int c;cin>>c;a[i].resize(c);for(int j=0;j<c;++j) {cin>>a[i][j];a[i][j]--;if(num[a[i][j]]==(-1)) num[a[i][j]]=i;} reverse(a[i].begin(),a[i].end());}
    int cnt[11]={0};
    for(int i=0;i<n;++i)
    {
        cnt[num[i]+1]++;
    }
    if(n==1)
    {
        cout<<"ACCEPTED";
        return 0;
    }
    if(cnt[0]!=0)
    {
        cout<<"REJECTED";
        return 0;
    }
    int cnt1[k+1];
    int o[n];
    bool ok=1;
    for(int i1=0;i1<=cnt[1];++i1)
    for(int i2=0;i2<=cnt[2];++i2)
    for(int i3=0;i3<=cnt[3];++i3)
    for(int i4=0;i4<=cnt[4];++i4)
    for(int i5=0;i5<=cnt[5];++i5)
    for(int i6=0;i6<=cnt[6];++i6)
    for(int i7=0;i7<=cnt[7];++i7)
    for(int i8=0;i8<=cnt[8];++i8)
    for(int i9=0;i9<=cnt[9];++i9)
    for(int i10=0;i10<=cnt[10];++i10)
    {
        for(int i=0;i<=k;++i) cnt1[i]=0;
        int v[11]={0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10};
        for(int i=0;i<n;++i)
        {
            int x=num[i]+1;
            o[i]=(cnt1[x]>=v[x]);
            cnt1[x]++;
        }
        for(int i=0;i<k;++i)
        {
            int cnt=0;
            for(int h:a[i]) {cnt+=o[h];o[h]=0;}
            for(int l=0;l<cnt;++l) o[a[i][l]]=1;
        }
        for(int i=0;i<n-1;++i)
        {
            ok=(ok && o[i+1]>=o[i]);
        }
        if(!ok)
        {
            cout<<"REJECTED";
            return 0;
        }
    }
    cout<<"ACCEPTED";
    return 0;
}