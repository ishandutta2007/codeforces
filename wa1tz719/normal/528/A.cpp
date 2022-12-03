#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
set<int> hang;
set<int> lie;
map<int,int> max_hang;
map<int,int> max_lie;
set<int> max_hang_num;
set<int> max_lie_num;
long long query()
{
    long long p=1;
    set<int>::iterator ii;
    ii=max_hang_num.end();
    ii--;
    p=p*(*ii);
    ii=max_lie_num.end();
    ii--;
    p=p*(*ii);
    return p;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    int i;
    hang.insert(0);
    hang.insert(n);
    lie.insert(0);
    lie.insert(m);
    max_lie[m]=1;
    max_hang[n]=1;
    max_lie_num.insert(m);
    max_hang_num.insert(n);
    for (i=0;i<k;i++)
    {
        char oper;
        int t;
        cin>>oper;
        cin>>t;
        if (oper=='H')
        {
            set<int>::iterator ii;
            ii=(lie.lower_bound(t));
            int ty=(*ii);
            ii--;
            int tx=(*ii);
            max_lie[ty-tx]--;
            if (max_lie[ty-tx]==0)
            {
                max_lie_num.erase(ty-tx);
            }
            lie.insert(t);
            max_lie[t-tx]++;
            max_lie[ty-t]++;
            max_lie_num.insert(t-tx);
            max_lie_num.insert(ty-t);
        }
        else
        {
            set<int>::iterator ii;
            ii=(hang.lower_bound(t));
            int ty=(*ii);
            ii--;
            int tx=(*ii);
            max_hang[ty-tx]--;
            if (max_hang[ty-tx]==0)
            {
                max_hang_num.erase(ty-tx);
            }
            hang.insert(t);
            max_hang[t-tx]++;
            max_hang[ty-t]++;
            max_hang_num.insert(t-tx);
            max_hang_num.insert(ty-t);
        }
        cout<<query()<<endl;
    } 
    return 0;
}