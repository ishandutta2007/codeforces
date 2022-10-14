#include <bits/stdc++.h>
using namespace std ;
int t , n ;
void solve ( ) {
    scanf ( "%d" , & n ) ;
    for ( int b = 2 ; ; b ++ ) {
        int a = n - b - 1 , c = 1 ;
        if ( a + b + c == n && __gcd ( a , b ) == c ) {
            printf ("%d %d %d \n" , a , b , c ) ;
            return ;
        }
    }
}
int main ( ) {
    scanf ( "%d" , & t ) ;
    while ( t -- ) {
        solve ( ) ;
    }
    return 0 ;
}