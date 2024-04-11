#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int maxn=1000;

map <string, int> mp;
long long g[maxn][maxn],n,a,b,k,f,n1,st[360007],top,res;

bool cmp(long long a, long long b) {return a>b;}

int main()
{
    cin >> n >> a >> b >> k >> f;
    string last="";
    for (int i=1; i<=n; ++i)
    {
        string s1,s2;
        cin >> s1 >> s2;
        if (mp[s1]==0) mp[s1]=++n1;
        if (mp[s2]==0) mp[s2]=++n1;
        if (last==s1) g[mp[s1]][mp[s2]]+=b, res+=b;
        else g[mp[s1]][mp[s2]]+=a, res+=a;
        last=s2;
    }
    for (int i=1; i<=n1; ++i)
        for (int j=1; j<=i; ++j)
            if (g[i][j]+g[j][i]>f) st[++top]=g[i][j]+g[j][i]-f;
    sort(st+1,st+top+1,cmp);
    for (int i=1; i<=k; ++i) res-=st[i];
    cout << res;
      
}