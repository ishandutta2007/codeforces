#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int64_t n, k;
    cin>>n>>k;
    int64_t suma=0;
    for(int  i=0; i<n; i++)
    {
        int a;
        cin>>a;
        suma+=a;
    }
    int64_t kiek=0;
    while(2*(suma+kiek*k)<(2*k-1)*(n+kiek))
        kiek++;
    cout<<kiek;
    return 0;
}