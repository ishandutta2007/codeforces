#include <iostream>
#include <vector>
#include <algorithm>
#define N 200005
#define INF 200005
using namespace std;
int a[N];
int gdzie[N];
int mini[N];
vector<int> pra[N];
vector<int> lew[N];
int odp[N];
vector< pair<int, int> > stos;
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<=n-1; i++)
    {
        cin>>a[i];
        a[i]--;
        gdzie[a[i]]=i;
        odp[i]=INF;
    }
    int l;
    int x;
    for(int i=0; i<=n-1; i++)
    {
        cin>>l;
        l--;
        if(gdzie[l]<i)
        {
            x=n+gdzie[l]-i;
            pra[x].push_back(n-1-gdzie[l]);
            lew[x+n].push_back(gdzie[l]);
        }
        else
        {
            x=gdzie[l]-i;
            pra[x].push_back(n-1-gdzie[l]);
            lew[x+n].push_back(gdzie[l]);
        }
    }
    int maxi;
    int cos;
    for(int i=0; i<2*n; i++)
    {
        maxi=-1;
        for(int j=0; j<pra[i].size(); j++)
        {
            maxi=max(maxi, pra[i][j]);
        }
        if(maxi>=0)
        {
            stos.push_back( make_pair(i, maxi) );
        }
        while(stos.size() && stos[stos.size()-1].first + stos[stos.size()-1].second < i)
        {
            stos.pop_back();
        }
        cos=i;
        if(cos>=n)
        {
            cos-=n;
        }
        if(stos.size())
        {
            odp[cos]=min(odp[cos], i-stos[stos.size()-1].first);
        }
    }
    stos.clear();
    for(int i=2*n-1; i>=0; i--)
    {
        maxi=-1;
        for(int j=0; j<lew[i].size(); j++)
        {
            maxi=max(maxi, lew[i][j]);
        }
        if(maxi>=0)
        {
            stos.push_back( make_pair(i, maxi) );
        }
        while(stos.size() && stos[stos.size()-1].first - stos[stos.size()-1].second > i)
        {
            stos.pop_back();
        }
        cos=i;
        if(cos>=n)
        {
            cos-=n;
        }
        if(stos.size())
        {
            odp[cos]=min(odp[cos], stos[stos.size()-1].first-i);
        }
    }
    cout<<odp[0]<<endl;
    for(int i=1; i<=n-1; i++)
    {
        cout<<odp[n-i]<<endl;
    }
    // system("pause");
    return 0;
}