#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int mas[100003];
vector <int> ball[100002];
int rez[100002][3];
int ind_rez;
int get ( int ind, int rezin )
{
    int index[3], cur[3];
    int count=0;
    while ( count<3 )
    {
          if ( ind==0 )
             return -1;
          if ( ball[ind].size()>0 )
          {
               int size=ball[ind].size();
               int t=ball[ind][size-1];
               ball[ind].pop_back();
               index[count]=ind-1;
               cur[count]=t;
               rez[rezin][count]=t;
               count++;
          }
          else
              ind--;
    } 
    for ( int i=0; i<3; i++ )
        ball[index[i]].push_back(cur[i]);
    return ind;    
}
int main()
{
    int max_count=1;
    int n;
    scanf("%i", &n);
    for ( int i=0; i<n; i++ )
        scanf("%i", &mas[i]);
    sort(mas, mas+n);
    int l=mas[0], count=1;
    for ( int i=1; i<n; i++ )
    {
        if ( l==mas[i] )
           count++;
        else
        {
            if ( max_count<count )
               max_count=count;
            ball[count].push_back(l);
            l=mas[i];
            count=1;
        }
    }
    
    ball[count].push_back(l);
    if ( max_count<count )
       max_count=count;
    /*
    for ( int i=1; i<=max_count; i++ )
    {
        for ( int s=0; s<ball[i].size(); s++ )
            printf("%i ", ball[i][s]);
        printf("\n");
    }*/
    int flag=0;
    while ( true )
    {
          flag=get(max_count, ind_rez);
          if ( flag==-1 )
             break;
          ind_rez++;
    }
    printf("%i\n", ind_rez);
    for ( int i=0; i<ind_rez; i++ )
    {
        sort(rez[i], rez[i]+3);
        printf("%i %i %i\n", rez[i][2], rez[i][1], rez[i][0]);
    }
    scanf("%i", &n);
    return 0;
}