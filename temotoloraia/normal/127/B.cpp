# include <iostream>
using namespace std;
long long n, i, a[1000], s, k;
main()
{
   cin >> n;
   for (i=0;i < n;i++)
   {
      cin >> k;
      a[k] = a[k] + 1;
   }
   for  (i=0; i< 1000; i++)
   {
       s = s + (a[i] / 2);

   }

   s = s / 2;
   cout << s;
}