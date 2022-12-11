#include <iostream>
#include <algorithm>
using namespace std;
struct card
{
       int a, b;
};
bool cmp ( card a, card b )
{
     if ( a.b>b.b )
        return true;
     else if ( a.b<b.b )
          return false;
     else
     {
         if ( a.a>b.a )
            return true;
         return false;
     }
}
card mas[2000];
int main()
{
    int n;
    cin >> n;
    int ch=1, rez=0;
    for ( int i=0; i<n; i++ )
        cin >> mas[i].a >> mas[i].b;
    sort(mas, mas+n, cmp);
    for ( int i=0; i<n; i++ )
    {
        if ( ch==0 )
           break;
        ch--;
        ch+=mas[i].b;
        rez+=mas[i].a;
    }
    cout << rez;
    cin >> n;
    return 0;
}