#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct sim
{
    int kol;
    char s;
};
int po[2000];
int simple[2000];
sim small[2000];
int in, l, indr;
char stroka[1001];
bool cmp ( sim a, sim b )
{
    if ( a.kol>b.kol )
        return false;
    return true;
}
void gen ( )
{
    for ( int i=2; i<=l; i++ )
    {
        bool h=true;
        for ( int s=2; s*s<=i; s++ )
        {
            if ( i%s==0 )
            {
                h=false;
                break;
            }
        }
        if ( h )
        {
            simple[in]=i;
            in++;
        }
    }
}
char search_ma ( int &in, int &ko, int ma )
{
    char rez;
    for ( int i=0; i<=ma; i++ )
    {
        if ( small[i].kol>ko )
        {
            ko=small[i].kol;
            rez=small[i].s;
            in=i;
        }
    }
    return rez;
}
int main()
{
    string str;
    cin >> str;
    for ( int i=0; i<str.length(); i++ )
        stroka[i]=str[i];
    l=str.length();
    gen();
    int flag=0;
    for ( int i=0; i<in; i++ )
    {
        flag++;
        bool h=false;
        int start=simple[i];
        int ns=simple[i+1];
        if ( ns==0 )
            ns=100000;
        for ( int s=2; s<=l; s++  )
        {
            if ( s%start==0 )
            {
                po[s]=flag;
            }
            if ( po[s]==flag )
            {
                if ( s%ns==0 )
                    h=true;
            }
        }
        if ( h )
            flag--;
    }   
    flag++;
    po[1]=flag;
    sort(stroka, stroka+l);
    small[0].s=stroka[0];
    small[0].kol=1;
    int ins=0;
    for ( int i=1; i<l; i++ )
    {
        if ( small[ins].s==stroka[i] )
        {
            small[ins].kol++;
        }
        else
        {
            ins++;
            small[ins].s=stroka[i];
            small[ins].kol=1;
        }
    }
    
    int f=1;
    while ( f<=flag )
    {
        int mai=-1, kolma=-1;
        char ma=search_ma(mai, kolma, ins);
        for ( int i=1; i<=l; i++ )
        {
            if ( po[i]==f )
            {
                str[i-1]=ma;
                kolma--;
            }
        }
        if ( kolma<0 )
        {
            cout << "NO";
            return 0;
        }
        small[mai].kol=kolma;
        f++;
    }
    cout << "YES\n";
    cout << str;
    return 0;
}