#include <iostream>
#include <algorithm>
#define uint long long int
#define N 100005
using namespace std;
uint t[N];
int main()
{
    uint n, k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    sort(t+1, t+1+n);
    uint maxi=0;
    uint faj=0;
    uint aktsum=0;
    uint pal=1;
    for(int i=1; i<=n; i++)
    {
        aktsum+=(t[i]-t[i-1])*(i-pal);
        while(aktsum>k)
        {
            aktsum-=t[i]-t[pal];
            pal++;
        }
        if(i-pal+1>maxi)
        {
            maxi=i-pal+1;
            faj=t[i];
        }
    }
    cout<<maxi<<" "<<faj<<endl;
    // system("pause");
    return 0;
}