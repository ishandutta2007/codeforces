#include <iostream>
using namespace std;
int n;
int mas[1000][1000];
int check ( int i, int s )
{
    int c1=0, c2=0;
    for ( int q=0; q<n; q++ )
    {
        c1+=mas[q][s];
        c2+=mas[i][q];
    }
    if ( c1>c2 )
       return 1;
    return 0;
}
int main()
{
    int rez=0;
    cin >> n;
    for ( int i=0; i<n; i++ )
    {
        for ( int s=0; s<n; s++ )
            cin >> mas[i][s];
    }
    for ( int i=0; i<n; i++ )
    {
        for ( int s=0; s<n; s++ )
            rez+=check(i, s);
    }
    cout << rez;
    cin >> n;
    return 0;
}