#include <iostream>
using namespace std;
int mas[4];
int main()
{
    int n, count=0;
    cin >> n;
    for ( int i=0; i<n; i++ )
    {
        int a;
        cin >> a;
        mas[a-1]++;
    }
    count+=mas[3];
    count+=mas[2];
    mas[0]-=mas[2];
    count+=(mas[1]+1)/2;
    if ( mas[1]%2==1 )
         mas[0]-=2;
    if ( mas[0]>0 )
       count+=(mas[0]+3)/4;
    cout << count;
    cin >> n;
    return 0;
}