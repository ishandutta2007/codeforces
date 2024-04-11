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

string a[105];
vector<string> v;
int vis[105];
int isp(string s)
{
    string t = s;
    reverse(all(t));
    return t == s;
}
string anss;
int main()
{
    int n,m;
    cin>>n>>m;
    ii cin>>a[i];
    for(int i=1;i<=n;++i) {
        if(vis[i]) continue;
        for(int j=i+1;j<=n;++j) {
            if(vis[j]) continue;
            string tmp = a[j];
            reverse(all(tmp));
            if(tmp == a[i])
            {
                vis[i] = vis[j] = 1;
                anss += a[i];
            }
        }
    }
    string tmp = anss;
    reverse(all(tmp));
    for(int i=1;i<=n;++i)
    {
        if(vis[i]) continue;
        if(isp(a[i]))
        {
            anss += a[i];
            break;
        }
    }
    anss += tmp;
    cout << anss.size() << endl;
    cout << anss << endl;
    
}