#include <bits/stdc++.h>
 
using namespace std;
 
char tab[1003][1003];
pair<int,int> a={-1,-1},b={-1,-1},c={-1,-1},d={-1,-1};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
 
    int t; cin>>t;
    while (t--)
    {
        a={-1,-1},b={-1,-1},c={-1,-1},d={-1,-1};
        
        int n,m; cin>>n>>m;
        for (int i=0;i<n;i++) cin>>tab[i];
 
        vector<pair<int,int>> interesting;
 
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (tab[i][j]=='B')
        {
            if (a.first==-1 || i+j>a.first+a.second) a={i,j};
            if (b.first==-1 || i+j<b.first+b.second) b={i,j};
            if (c.first==-1 || i-j>c.first-c.second) c={i,j};
            if (d.first==-1 || i-j<d.first-d.second) d={i,j};
        }
 
        interesting.push_back(a);
        interesting.push_back(b);
        interesting.push_back(c);
        interesting.push_back(d);
 
        int ans=1e9; pair<int,int> opt;
        for (int i=0;i<n;i++) for (int j=0;j<m;j++)
        {
            int dist=0;
            for (auto it : interesting) dist=max(dist,abs(i-it.first)+abs(j-it.second));
            if (dist<ans) ans=dist,opt={i,j};
        }
 
        cout<<opt.first+1<<" "<<opt.second+1<<"\n";
    }
}