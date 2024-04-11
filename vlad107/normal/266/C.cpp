#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>

#define X first
#define Y second

using namespace std;

set<int>h[1100], v[1100];
vector< pair<int, pair<int, int> > >ans;
int n;
void myswap1(int x, int y)
{
     for (int i=1; i<=n; i++)
         h[i].erase(x), h[i].erase(y);
     v[x].swap(v[y]);
     for (set<int>::iterator it=v[x].begin(); it!=v[x].end(); ++it)
         h[*it].insert(x);
     for (set<int>::iterator it=v[y].begin(); it!=v[y].end(); ++it)
         h[*it].insert(y);     
}
void sort1(int l, int r)
{
    
     if (l==r)
        return ;
      
     int med=v[l+rand()*rand()%(r-l+1)].size(), i=l, j=r;  

     do
     {
        
         while ( v[i].size()>med )
               i++;
         while ( v[j].size()<med )
               j--;
         
         if (i<=j)
         {
            
               if (i!=j)
                  ans.push_back( make_pair(2, make_pair(i, j) ) );        
               myswap1(i, j);
               i++; j--;
         }
     }
     while (i<=j);
     if (l<j)
        sort1(l, j);
     if (i<r)
        sort1(i, r);
}
inline int last(int x)
{
       set<int>::iterator it;
       it=h[x].end();
       if ( h[x].empty() )
          return 0;
       --it;
       return (*it);       
}
void sort2(int l, int r)
{
     if (l==r)
        return;
    
     int med=last(l+rand()*rand()%(r-l+1)), i=l, j=r;
    
     do
     {
         while ( last(i)<med )
               i++;
         while ( last(j)>med )
               j--;
         if (i<=j)
         {

                if (i!=j)
                   ans.push_back( make_pair(1, make_pair(i, j)) );
                h[i].swap( h[j] );        
                i++; j--;
         }
     }
     while (i<=j);
     if (l<j)
        sort2(l, j);
     if (i<r)
        sort2(i, r);  
}

int main ()
{
    srand(2310);
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int x, y;
        cin>>x>>y;
        h[x].insert(y);
        v[y].insert(x);
    }
    sort1(1, n);
   
    sort2(1, n);
  
    cout<<ans.size()<<endl;
    for (int i=0; i<ans.size(); i++)
        cout<<ans[i].X<<" "<<ans[i].Y.X<<" "<<ans[i].Y.Y<<endl;
    return 0;
}