#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
//random_device rng;
//mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 400005;
int a[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ii cin>>a[i];
        vector<int> v;
        int cnt = 1;
        a[n+1] = -1;
        for(int i=1;i<=n;++i)
        {
            if(a[i] != a[i+1])
            {
                v.push_back(cnt);
                cnt = 1;
            }
            else cnt++;
        }
//        for(int i:v) cout<<i<<" ";cout<<endl;
        int tot=0;
        for(int i=0;i<v.size();++i)
        {
            if( 2*(tot + v[i]) > n )
            {
                v.resize(i);
                break;
            }
            tot += v[i];
        }
//        for(int i:v) cout<<i<<" ";cout<<endl;
        int g = v[0];
        int sum = 0;
        for(int i=1;i<v.size();++i) sum += v[i];
        int tmp = 0;
        for(int i=1;i<v.size();++i)
        {
            tmp += v[i];
            if(tmp > g) break;
        }
        int s=tmp,b=sum-tmp;
        if(g<s && g<b) cout<<g<<" "<<s<<" "<<b<<endl;
        else cout<<"0 0 0"<<endl;
    }
}