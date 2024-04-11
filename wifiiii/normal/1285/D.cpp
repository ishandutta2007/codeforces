
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'
 

int dfs(int p,vector<int> v)
{
    if(p<0) return 0;
    vector<int> v0;
    vector<int> v1;
    for(int i:v)
    {
        if(i&(1<<p)) v0.push_back(i);
        else v1.push_back(i);
    }
    if(v0.empty() || v1.empty())
    {
        if(v0.size()) return dfs(p-1,v0);
        if(v1.size()) return dfs(p-1,v1);
    }
    int ret = 2e9;
    return (1<<p) + min(dfs(p-1,v0),dfs(p-1,v1));
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    ii
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    cout << dfs(30,v) << endl;
}