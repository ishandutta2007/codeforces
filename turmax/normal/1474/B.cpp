#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
bool is[maxn];
vector <int> pr;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    is[0]=true;is[1]=true;
    for(int i=0;i<maxn;++i) if(!is[i]) for(int j=(2*i);j<maxn;j+=i) is[j]=true;
    for(int i=0;i<maxn;++i) if(!is[i]) pr.push_back(i);
    int t;
    cin>>t;
    while(t--)
    {
        int d;
        cin>>d;
        int p1=*lower_bound(pr.begin(),pr.end(),d+1);
        int p2=*lower_bound(pr.begin(),pr.end(),p1+d);
        cout<<(p1*p2)<<endl;
    }
    return 0;
}