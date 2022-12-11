#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int mas[100][100];
int vert[100], gor[100];
int a, b, c;
bool check (  int f, int s, int t )
{
    if ( f==a )
    {
        if ( (s==b&&t==c)||(s==c&&t==b) )
            return true;
        return false;
    }
    if ( s==a )
    {
        if ( (f==b&&t==c)||(f==c&&t==b) )
            return true;
        return false;
    }
    if ( t==a )
    {
        if ( (s==b&&f==c)||(s==c&&f==b) )
            return true;
        return false;
    }
    else
        return false;
}
int main()
{
freopen ("input.txt", "r", stdin);
freopen ("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    int all=0;
    for ( int i=0; i<n; i++ )
    {
        for ( int s=0; s<m; s++ )
        {
            cin >> mas[i][s];
            all+=mas[i][s];
            vert[i]+=mas[i][s];
            gor[s]+=mas[i][s];
        }
    }
    cin >> a >> b >> c;
    int rez1=0, rez2=0;
    int otv=0;
    for ( int i=0; i<m-1; i++ )
    {
        rez1+=gor[i];
        rez2=0;
        for ( int s=i+1; s<m-1; s++ )
        {
            rez2+=gor[s];
            if ( check(rez1, rez2, all-rez1-rez2) )
                otv++;
        }
    }
    rez1=0, rez2=0;
    for ( int i=0; i<n-1; i++ )
    {
        rez1+=vert[i];
        rez2=0;
        for ( int s=i+1; s<n-1; s++ )
        {
            rez2+=vert[s];
            if ( check(rez1, rez2, all-rez1-rez2) )
                otv++;
        }
    }
    cout << otv;
    return 0;
}