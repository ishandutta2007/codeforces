#include <iostream>
#include <string>
using namespace std;
string name[1000], fri[100][100];
int main()
{
    int n, k;
    cin >> n >> k;
    int rez=0;
    while ( k%n==0 )
    {
        k/=n;
        rez++;
    }
    if ( k==1 )
        cout << "YES\n" << rez-1;
    else
        cout << "NO";
    return 0;
}