#include <iostream>
using namespace std;
int mas[1000000], sk[100000];
int ind;
int n;
void del ( int n )
{
     for ( int i = 1; i * i <=n; i++ )
     {
         if ( n % i == 0 )
              mas[ind++] = i;
     }
}
int ans ( int ind )
{
    int max_rez = -100000000;
    for ( int i = 0; i < ind; i++ )
    {
        int rez = 0;
        int now = i;
        for ( int s = 0; s < n/ind; s++ )
        {
            now += ind;
            if ( now >= n )
               now %= n;
            rez += sk[now];
        }
        if ( max_rez < rez )
           max_rez = rez;
    }
    return max_rez;
}
int main()
{
    int answer = -100000000;
    cin >> n;
    for ( int i = 0; i < n; i++ )
        cin >> sk[i];
    del(n);
    for ( int i = 0; i < ind; i++ )
    {
        if ( n/mas[i] > 2 )
        {
            int k = ans(mas[i]);
            if ( k > answer )
               answer = k;
        }
        if ( mas[i] > 2 )
        {
             int k = ans(n/mas[i]);
             if ( k > answer )
                answer = k;
        }
    }
    cout << answer;
    cin >> n;
    return 0;
}