#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a[n];
        int mi1=1e18;int ma1=(-1e18);int c1=0;int c2=0;int el1=(-1);int el2=(-1);int el3=(-1);
        for(int i=0;i<n;++i) {a[i].resize(3);cin>>a[i][0]>>a[i][1]>>a[i][2];
        if(el3==(-1) || a[i][1]-a[i][0]>a[el3][1]-a[el3][0] || (a[i][1]-a[i][0]==a[el3][1]-a[el3][0] && a[i][2]<a[el3][2])) el3=i;
        if(a[i][0]<mi1 || (a[i][0]==mi1 && a[i][2]<c1)) {c1=a[i][2];mi1=a[i][0];el1=i;}
        if(a[i][1]>ma1 || (a[i][1]==ma1 && a[i][2]<c2)) {c2=a[i][2];ma1=a[i][1];el2=i;}
        if(el3!=(-1) && a[el3][1]-a[el3][0]==(ma1-mi1) && a[el3][2]<c1+c2) {cout<<a[el3][2]<<endl;}
        else {cout<<c1+c2<<endl;}
        }
    }
    return 0;
}