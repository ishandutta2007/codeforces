# include <iostream>
# include <algorithm>
using namespace std;
long long n, d, s, i, j, k, a[200000];
int main()
{
    cin >> n >> d;
    i = 0;
    while (i < n)
    {
          cin >> a[i];
          i = i + 1;
   }
    
    i = 0; j = 1; k = 0; s = 0;
    while (i < n)
    {
          
          while ((a[j] - a[i] <= d) && (j < n)) {
                j++;
          }
          
          k = j - i - 1;
          if (k >= 2)
          {
             s = s + (k * (k - 1))/2;
          }
         
       i++;   
    }
    
    cout << s;
    //system("pause");
    return 0;
}