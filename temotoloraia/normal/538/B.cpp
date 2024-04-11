#include<iostream>
using namespace std;
int masivi[999];
int main()
{
    int i, j, k, n;
    cin>>n;
    for (i = 0; n; i++)
    {
        for (j = 1; j <= n; j *= 10);
        k = 0;
        while (j /= 10)
        {
            if (n / j % 10)k += j;
        }
        masivi[i] = k;
        n -= k;
    }
    cout<<i<<endl;
    while (i--)
cout<<masivi[i]<<" ";
}