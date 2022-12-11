#include <bits/stdc++.h>
using namespace std;
#define Maxn 50007
int n,x[Maxn],y[Maxn],z[Maxn];
map<pair<int,int>,vector<pair<int,int> > >s;
map<int,vector<pair<int,int> > >ss;
vector<pair<int,int> >sss;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
    for (int i=1;i<=n;i++)
        s[make_pair(x[i],y[i])].push_back(make_pair(z[i],i));
    for (map<pair<int,int>,vector<pair<int,int> > >::iterator it=s.begin();it!=s.end();it++)
    {
        sort((*it).second.begin(),(*it).second.end());
        if ((int)(*it).second.size()>=2)
        {
            for (int i=0;i<(int)(*it).second.size()-1;i+=2)
                printf("%d %d\n",(((*it).second)[i]).second,(((*it).second)[i+1]).second);
        }
        if ((int)(*it).second.size()%2==1) ss[(*it).first.first].push_back(make_pair((*it).first.second,((*it).second)[(int)(*it).second.size()-1].second));
    }
    for (map<int,vector<pair<int,int> > >::iterator it=ss.begin();it!=ss.end();it++)
    {
        sort((*it).second.begin(),(*it).second.end());
        if ((int)(*it).second.size()>=2)
        {
            for (int i=0;i<(int)(*it).second.size()-1;i+=2)
                printf("%d %d\n",(((*it).second)[i]).second,(((*it).second)[i+1]).second);
        }
        if ((int)(*it).second.size()%2==1) sss.push_back(make_pair((*it).first,((*it).second)[(int)(*it).second.size()-1].second));
    }
    for (int i=0;i<(int)sss.size()-1;i+=2)
        printf("%d %d\n",sss[i].second,sss[i+1].second);
    return 0;
}