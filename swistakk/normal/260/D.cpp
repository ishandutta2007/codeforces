#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
#define uint long long int
#define N 1000005
using namespace std;
vector<pair<uint, uint> > wi[2];
int main()
{
    ios_base::sync_with_stdio(0);
    uint n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        uint kol, sum;
        cin>>kol>>sum;
        wi[kol].push_back(make_pair(-sum, i) );
    }
    sort(wi[0].begin(), wi[0].end());
    sort(wi[1].begin(), wi[1].end());
    for(uint ind=0; ind<=1; ind++)
    {
        for(uint i=0; i<wi[ind].size(); i++)
        {
            wi[ind][i].first*=-1;
        }
    }
    uint obrot=0;
    while(obrot<n-1)
    {
        obrot++;
        int gd;
        if(wi[0][wi[0].size()-1].first<wi[1][wi[1].size()-1].first)
        {
            gd=0;
        }
        else
        {
            gd=1;
        }
        if(wi[gd].size()==1)
        {
            gd=1-gd;
        }
        cout<<wi[0][wi[0].size()-1].second<<" "<<wi[1][wi[1].size()-1].second<<" "<<wi[gd][wi[gd].size()-1].first<<endl;
        wi[1-gd][wi[1-gd].size()-1].first-=wi[gd][wi[gd].size()-1].first;
       
        wi[gd].pop_back();
    }
    return 0;
}