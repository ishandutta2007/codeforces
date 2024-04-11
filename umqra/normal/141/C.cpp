#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct people
{
       string name;
       int a, h;
};
bool cmp ( people a, people b )
{
     if ( a.a>b.a )
        return false;
     return true;
}
people mas[4000];
int height[4000];
int ind=0;
int raz=0;
bool push_mas ( int ind, int val )
{
     if ( ind>raz )
        return false;
     raz++;
     int t=height[ind];
     height[ind]=val;
     for ( int i=ind+1; i<=raz; i++ )
     {
         int t2=height[i];
         height[i]=t;
         t=t2;
     }
     return true;
}
int main()
{
    int n;
    cin >> n;
    for ( int i=0; i<n; i++ )
        cin >> mas[i].name >> mas[i].a;
    sort(mas, mas+n, cmp);
    int l=-1;
    for ( int i=0; i<n; i++ )
    {
        if ( l==mas[i].a )
        {
           if ( !push_mas(ind+1, i) )
           {
                cout << -1;
                cin >> n;
                return 0;
           }
           ind++;
        }
        else
        {
           l=mas[i].a;
           ind=raz-mas[i].a;
           if ( raz-mas[i].a<0 )
           {
                cout << -1;
                cin >> n;
                return 0;
           }
           push_mas(raz-mas[i].a, i);
        }
    }
    for ( int i=0; i<raz; i++ )
        mas[height[i]].h=i+1;
    for ( int i=0; i<n; i++ )
        cout << mas[i].name << ' ' << mas[i].h << '\n';
    cin >> n;
    return 0;
}