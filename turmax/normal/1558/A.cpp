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
        int a,b;
        cin>>a>>b;
        int mi=max(a,b)-(a+b+1)/2;
        int ma=(a+b)-((a+b)/2-min(a,b));
        vector <int> v;
        for(int k=mi;k<=ma;++k) if((a+b)%2==1 || (k%2)==(((max(a,b)-min(a,b)))/2)%2) v.push_back(k);
        cout<<v.size()<<endl;
        for(auto h:v) cout<<h<<' ';
        cout<<endl;
    }
    return 0;
}