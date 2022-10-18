#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

map <long long, int> mp;
long long N,M,n_[2],st[2][10000],cur;
 

int main()
{
    cin >> N >> M;
    for (int i=1; i<=N; ++i)
    {
        string a;
        cin >> a;
        long long h=0;
        for (int j=0; j<a.length(); ++j) h=(h*9+(a[j]-'a'+1));
        mp[h]++;
    }
    for (int i=1; i<=M; ++i)
    {
        string a;
        cin >> a;
        cur=0;
        st[cur][1]=0;
        n_[0]=1; n_[1]=0;
        for (int j=0; j<a.length(); ++j) 
        {
            if (a[j]=='?')
            {
                n_[cur^1]=0;
                for (int k=1; k<=n_[cur]; ++k)
                {
                    n_[cur^1]++; st[cur^1][n_[cur^1]]=st[cur][k];
                    for (int z=1; z<=5; ++z)
                    {
                        n_[cur^1]++;
                        st[cur^1][n_[cur^1]]=(st[cur][k]*9+z);
                    }
                }
                cur^=1;
            }
            else for (int k=1; k<=n_[cur]; ++k) st[cur][k]=(st[cur][k]*9+(a[j]-'a'+1));
        }
        long long res=0;
        sort(st[cur]+1, st[cur]+n_[cur]+1);
        res+=mp[st[cur][1]];
        for (int j=2; j<=n_[cur]; ++j) if (st[cur][j]!=st[cur][j-1]) res+=mp[st[cur][j]];    
        cout << res << endl;        
    }
}