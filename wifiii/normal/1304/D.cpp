#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//random_device rng;
//mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
int a[200005],b[200005];
void rev(int *s, int l, int r)
{
    while(l < r)
    {
        swap(s[l], s[r]);
        ++l;--r;
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        ii a[i]=i,b[i]=n-i+1;
        vector<pair<char,int>> v;
        int cnt=0;
        char ch=-1;
        for(int i=0;i<=s.size();++i)
        {
            if(s[i] == ch) ++cnt;
            else
            {
                if(cnt) v.push_back({ch, cnt});
                cnt = 1;
            }
            ch = s[i];
        }
        int cur = 1;
        for(int i=0;i<v.size();++i)
        {
            if(v[i].first == '<')
            {
                rev(b,cur,cur+v[i].second);
            }
            else
            {
                rev(a,cur,cur+v[i].second);
            }
            cur += v[i].second;
        }
        ii cout<<b[i]<<" ";cout<<endl;
        ii cout<<a[i]<<" ";cout<<endl;
    }
}