#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define N 100005
using namespace std;
pair<int, int> tab[N];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int maxi=0;
    int ki, ai;
    for(int i=1; i<=n; i++)
    {
        cin>>ki>>ai;
        if(ai==1)
        {
            ki=ki+1;
        }
        else
        {
        ai--;
        while(ai)
        {
            ki++;
            ai/=4;
        }
        }
        maxi=max(maxi, ki);
    }
    cout<<maxi<<endl;
    return 0;
}