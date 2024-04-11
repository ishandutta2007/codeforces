#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
const int MAXN = 4e5 + 5;
const int N = 2e6 + 5;
using namespace std;
map<int, vector<int> > mapx;
map<int, vector<int> > mapy;
map<int, vector<int> >::iterator it;
int kraw[N][3];
int deg[N];
set<int> slo[N];
int newe;
void dfs(int w)
{
     while(!slo[w].empty())
     {
             if(w>MAXN)
             {
                       newe=*slo[w].begin();
                       slo[w].erase(newe);
                       slo[ kraw[newe][0] ].erase(newe);
                       kraw[ newe ][2]=1; 
                       dfs(kraw[newe][0]);
             }
             else
             {
                       newe=*slo[w].begin();
                       slo[w].erase(newe);
                       slo[ kraw[newe][1]].erase(newe);
                       dfs(kraw[newe][1]);
             }
     }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
            cin>>kraw[i][0]>>kraw[i][1];
            mapx[kraw[i][0]].push_back(i);
            mapy[kraw[i][1]].push_back(i);
    }
    int licz=1;
    for(it=mapx.begin(); it!=mapx.end(); it++)
    {
            while(!(*it).second.empty() )
            {
                   kraw[ (*it).second[(*it).second.size()-1] ][0] =licz;
                   (*it).second.pop_back();                
            }
            licz++;         
    }
    licz=1;
    for(it=mapy.begin(); it!=mapy.end(); it++)
    {
            while(!(*it).second.empty() )
            {
                   kraw[ (*it).second[(*it).second.size()-1] ][1] =licz;
                   (*it).second.pop_back();                
            }
            licz++;         
    }
    /* for(int i=1; i<=n; i++)
    {
            cout<<kraw[i][0]<<" ";
    }
    cout<<endl;
    for(int i=1; i<=n; i++)
    {
            cout<<kraw[i][1]<<" ";
    }
    cout<<endl; */
    for(int i=1; i<=n; i++)
    {
            kraw[i][1]+=MAXN;
            slo[kraw[i][0]].insert(i);
            slo[kraw[i][1]].insert(i);
            deg[kraw[i][0]]++;
            deg[kraw[i][1]]++;
    }
    int licz2=n+1;
    for(int i=1; i<=MAXN; i++)
    {
            if(deg[i]%2==1)
            {
                           kraw[licz2][0]=i;
                           kraw[licz2][1]=2*MAXN;
                           deg[2*MAXN]++;
                           slo[2*MAXN].insert(licz2);
                           slo[i].insert(licz2);
                           licz2++;
            }
    }
    for(int i=MAXN+1; i<=2*MAXN; i++)
    {
            if(deg[i]%2==1)
            {
                           kraw[licz2][0]=MAXN;
                           kraw[licz2][1]=i;
                           slo[MAXN].insert(licz2);
                           slo[i].insert(licz2);
                           licz2++;
            }
    }
    if(deg[MAXN]%2==1)
    {
                      kraw[licz2][0]=MAXN;
                      kraw[licz2][1]=2*MAXN;
                      slo[2*MAXN].insert(licz2);
                      slo[MAXN].insert(licz2);
    }
    /* for(int i=1; i<licz2; i++)
    {
            cout<<kraw[i][0]<<" "<<kraw[i][1]<<endl;
    } */
    for (int i = 1; i <= n; i++) {
      if (!slo[i].empty()) {
        dfs(i);
      }
    }
    //dfs(1);
    for(int i=1; i<=n; i++)
    {
            if(kraw[i][2]==0)
            {
              cout<<"r";
                             //cout<<"CARNATION"<<endl;
            }
            else
            {
              cout<<"b";
                        //     cout<<"ROSE"<<endl;
            }
    }
    cout<<"\n";;
    // system("pause");
    return 0;
}
/*
7
-26 4
0 3
27 -2
3 4
-13 2
15 34
0 23
*/
/*
5
1 3
4 4
1 1
3 4
1 4
*/