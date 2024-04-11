#include <iostream>
#include <algorithm>
using namespace std;
struct like
{
       int num, in;
};
bool cmp ( like a, like b )
{
     if ( a.num>b.num )
        return false;
     return true;
}
int fri[400][400], time[400][2], real[400];
like alex[400];
int main()
{
    int n;
    cin >> n;
    for ( int i=0; i<n; i++ )
    {
        for ( int s=0; s<n; s++ )
            cin >> fri[i][s];
    }
    for ( int i=0; i<n; i++ )
    {
        cin >> alex[i].num;
        real[i]=alex[i].num;
        alex[i].in=i;
    }
    sort(alex, alex+n, cmp);
    int mi=399, mi2=399;
    for ( int i=0; i<n; i++ )
    {
        if ( alex[i].in<mi )
        {
             swap(mi, mi2);
             mi=alex[i].in;
        }
        else if ( alex[i].in<mi2 )
             mi2=alex[i].in;
        time[i][0]=mi;
        time[i][1]=mi2;
        //cout << mi << ' ' << mi2 << '\n';
    }
    for ( int i=0; i<n; i++ )
    {
        for ( int s=0; s<n; s++ )
        {
            bool h=false;
            for ( int q=0; q<n; q++ )
            {
                int t=time[q][0];
                int t2=time[q][1];
                if ( real[t]==fri[i][s]&&real[t]!=i+1 )
                {
                    cout << q+1 << ' ';
                    h=true;
                    break;
                }
                if ( real[t2]==fri[i][s]&&real[t]==i+1 )
                {
                    cout << q+1 << ' ';
                    h=true;
                    break;
                }
            }
            if ( h )
                break;
        }
    }
    return 0;
    
}