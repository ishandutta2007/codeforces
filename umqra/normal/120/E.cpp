#include <iostream>
using namespace std;
int main()
{
freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int t;
    cin >> t;
   for ( int i=0; i<t; i++ )
   {
      int a;
     cin >> a;
    cout << (a+1)%2 << '\n';   
   }     
  return 0; 
}