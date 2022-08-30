#include <iostream>
#include <cstdio>
#define ld double
using namespace std;
int main()
{
    int n;
    ld wynik=0;
    ld ogon=0;
    ld p;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>p;
        ogon=p*(ogon+1);
        wynik+=(2*ogon-p);
    }
    printf("%.10lf\n", wynik);
    //cout<<wynik<<endl;
    //system("pause");
    return 0;
}