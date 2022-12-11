#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int p[3000][3000];
int start_[3000], end_[3000];
void pal ( string a )
{
     for ( int i = 0; i < a.length(); i++ )
     {
         for ( int s = 0; s <= min(i, (int)a.length() - i - 1); s++ )
         {
             if ( (p[i - s + 1][i + s - 1] && a[i - s] == a[i + s]) || s == 0 )
             {
                p[i - s][i + s] = 1;
                start_[i - s]++;
                end_[i + s]++;
             }
         }
         for ( int s = 0; s <= min(i - 1, (int)a.length() - i - 1); s++ )
         {
             if ( a[i - s - 1] == a[i + s] )
             {
                  if ( s == 0 || p[i - s][i + s - 1] )
                  {
                     p[i - s - 1][i + s] = 1;
                     start_[i - s - 1]++;
                     end_[i + s]++;
                  }
             }
         }
     }         
     return;
}
int main()
{
    long long rez = 0;
    string a;
    cin >> a;
    pal(a);
    for ( int i = 0; i < a.length(); i++ )
    {
        long long t = end_[i];
        long long k = 0;
        for ( int s = i + 1; s < a.length(); s++ )
            k += start_[s];
        rez += t * k;
    }
    cout << rez;
    cin >> a;
    return 0;
}