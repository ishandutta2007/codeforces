#include <iostream>
using namespace std;
int main()
{
    int r1, r2, d1, d2, c1, c2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    for ( int i=1; i<10; i++ )
    {
        for ( int s=1; s<10; s++ )
        {
            if ( i!=s )
            {
                 for ( int q=1; q<10; q++ )
                 {
                     if ( q!=s&&q!=i )
                     {
                          for ( int w=1; w<10; w++ )
                          {
                              if ( w!=i&&w!=s&&w!=q )
                              {
                                   if ( i+s==r1&&w+q==r2&&i+q==c1&&s+w==c2&&i+w==d1&&s+q==d2 )
                                   {
                                        cout << i << ' ' << s << '\n' << q << ' ' << w;
                                        cin >> r1;
                                        return 0;
                                   } 
                              }
                          }
                     }
                 }    
            }
        }
    }
    cout << -1;
    cin >> r1;
    return 0;
}