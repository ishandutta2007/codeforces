#include <stdio.h>
#include <map>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
map< pair<string,string> , int > mapa;
string srcc,dest,pre;
vector<int> sol;
bool comp(int a, int b){ return a>b;}
int main()
{
    int n,i,a,b,f,k;
    pre="$";
    scanf("%i %i %i %i %i",&n,&a,&b,&k,&f);
    for(i=0;i<n;i++)
    {
        //scanf("\n");
        cin >> srcc;
        cin >> dest;
        //printf("%i",i);
        int cost=a;
        if(i>0 && srcc.compare(pre)==0) cost=b;
        if(mapa.count(make_pair(srcc,dest))==0)
        {
            mapa[make_pair(dest,srcc)]+=cost;
        }
        else mapa[make_pair(srcc,dest)]+=cost;
        pre=dest;
    }
    map< pair<string,string> , int >::iterator it;
    for(it=mapa.begin();it!=mapa.end();it++) sol.push_back(it->second);
    sort(sol.begin(),sol.end(),comp);
    int ans=0;
    for(i=0;i<sol.size();i++)
    {
        if(i<k) ans+=min(sol[i],f);
        else ans+=sol[i];
    }
    printf("%i\n",ans);
    return 0;
}