#include <iostream>
#include <algorithm>
#include <vector>
#define N 100005
#define uint long long int
using namespace std;
uint sch[N];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>sch[i];
    }
    uint m;
    cin>>m;
    uint akth=0;
    int wsk=0;
    for(int i=1; i<=m; i++)
    {
        int w, h;
        cin>>w>>h;
        while(w>wsk)
        {
            akth=max(akth, sch[wsk]);
            wsk++;
        }
        akth=max(akth, sch[wsk]);
        cout<<akth<<endl;
        akth=akth+h;
    }
    //cout<<akth<<endl;
    return 0;
}