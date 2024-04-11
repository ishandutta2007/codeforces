#include <iostream>
using namespace std;
int mas[100000];
int main()
{
    int n;
    cin >> n;
    for ( int i=0; i<n; i++ )
    {
        int a;
        cin >> a;
        mas[a-1]=i+1;
    }
    for ( int i=0; i<n; i++ )
        cout << mas[i] << ' ';
    return 0;
}