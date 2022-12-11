#include <iostream>
#include <algorithm>
using namespace std;
int mas[1000];
int main()
{
    int all=0, count=0;
    int time=6*60-10;
    int n;
    cin >> n;
    for ( int i=0; i<n; i++ )
        cin >> mas[i];
    sort(mas, mas+n);
    for ( int i=0; i<n; i++ )
    {
        time-=mas[i];
        if ( time<-6*60 )
           break;
        count++;
        if ( time<0 )
             all+=abs(time);
    }
    cout << count << ' ' << all;
    cin >> n;
    return 0;
}