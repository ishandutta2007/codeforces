#include<bits/stdc++.h>
using namespace std;
#define ll long long
int game[100];
vector<int>vec[100];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,w,l;
    cin>>n;
    ll m=(n*(n-1))/2;
    for(int i=1; i<m; i++)
    {
        cin>>w>>l;
        vec[w].push_back(l);
        game[w]+=1;
        game[l]+=1;
    }
    int p=0,q=0;
    for(int i=1; i<=n; i++)
    {
        if(game[i]!=n-1)
        {
            if(p==0)
                p=i;
            else
                q=i;
        }
    }
    for(int i=0;i<vec[p].size();i++)
    {
        int N=vec[p][i];
        for(int j=0;j<vec[N].size();j++)
        {
            if(vec[N][j]==q)
            {
                cout<<p<<" "<<q<<endl;
                return 0;
            }
        }
    }
    cout<<q<<" "<<p<<endl;
    return 0;
}