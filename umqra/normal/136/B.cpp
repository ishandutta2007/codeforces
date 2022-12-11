#include <iostream>
#include <string>
using namespace std;
int mas[100000];
string tri ( long long a )
{
       string rez="";
       while ( a>0 )
       {
             rez+=(a%3)+'0';
             a/=3;
       }
       return rez;
} 
string tor ( string a, string rez )
{
    string r="";
    for ( int i=0; i<min(a.length(), rez.length()); i++ )
    {
        int at=a[i]-'0';
        int ct=rez[i]-'0';
        int delta=ct-at;
        if ( delta<0 )
            delta+=3;
        r+=delta+'0';
    }
    if ( a.length()>rez.length() )
    {
        for ( int s=rez.length(); s<a.length(); s++ )
        {
            int delta=3-(a[s]-'0');
            if ( delta==3 )
                delta=0;
            r+=delta+'0';
        }
    }
    else if ( a.length()<rez.length() )
    {
        for ( int s=a.length(); s<rez.length(); s++ )
        {
            int delta=rez[s]-'0';
            r+=delta+'0';
        }
    }
    return r;
}
long long dec ( string a )
{
    long long rez=0;
    long long tri=1;
    for ( int i=0; i<a.length(); i++ )
    {
        int t=a[i]-'0';
        rez+=tri*t;
        tri*=3;
    }
    return rez;
}
int main()
{
    long long a, c;
    cin >> a >> c;
    string at=tri(a);
    string ct=tri(c);
    string rez=tor(at, ct);
    cout << dec(rez);
    return 0;
}