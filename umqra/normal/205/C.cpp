#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
ll ans ( int f, int l, ll center, int len )
{                      
    ll cnt = 0;
    ll t = 1;      
    for ( int i = 0; i < 17; i++ )
    {
        if ( i + 2 > len )
            break;
        for ( int s = 1; s < 10; s++ )
        {
            if ( len != i + 2 || (len == i + 2 && s < f) )
            {                    
                cnt += t;          
                continue;
            }
            if ( s == f )
            {
                if ( l < s )
                {
                    cnt += center;     
                    break;
                }
                if ( l > s )
                {   
                    cnt += center + 1;
                    break;
                }
                if ( l == s )
                {
                    cnt += center + 1;
                    break;
                }
            }   
            if ( s > f )
                break;

        }
        t *= 10;         
    }
    return cnt;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif  
    ll cnt_a = 0, cnt_b = 0;
    ll a, b;            
    cin >> a >> b;
    a--;
    ll za = a, zb = b;
    int la = 0, lb = 0, fa = 0, fb = 0;
    int len_a = 0, len_b = 0;
    ll ten_a = 1, ten_b = 1;
    while ( za > 0 )
    {
        fa = za % 10;     
        za /= 10;
        len_a++;
        ten_a *= 10;
    }
    while ( zb > 0 )
    {
        fb = zb % 10;
        zb /= 10;
        len_b++;
        ten_b *= 10;
    }
    la = a % 10;
    lb = b % 10;
    ll center_a = 0, center_b = 0;  
    //cout << fa << ' ' << la << endl;
    if ( len_a > 1 )
        center_a = (a / 10) % (ten_a / 100);
    if ( len_b > 1 )
        center_b = (b / 10) % (ten_b / 100); 
    if ( len_a <= 1 )
        cnt_a = a;
    else
        cnt_a = ans(fa, la, center_a, len_a) + 9;
    if ( len_b <= 1 )
        cnt_b = b;
    else
        cnt_b = ans(fb, lb, center_b, len_b) + 9;
    //cout << cnt_a << ' ' << cnt_b << endl;
    cout << cnt_b - cnt_a;
    return 0;
}