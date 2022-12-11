#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector <int> mas[30][3000];
int mi[30][3000];
int k;
string str;
char rez[300000];
void list_make ( int k, string a )
{
     int index = 0;
     for ( int i = 0; i < k; i++ )
     {
         for ( int s = 0; s < a.length(); s++ )
         {
              int x = a[s] - 'a';
              mas[x][i].push_back(index++);
         }
     }
     return;
}
void find2 ( int ind, int p, char a )
{
     int c = a - 'a';
     int index = 0;
     for ( int i = 0; i < mas[c][ind].size(); i++ )
     {
         if ( mas[c][ind][i] != -1 )
            index++;
         if ( index == p )
         {
              mas[c][ind][i] = -1;
              mi[c][ind]++;
              break;
         }
     }
     return;
}
void find ( char a, int p )
{
     int now = 0;
     for ( int i = 0; i < k; i++ )
     {
         int t = now;
         now += mas[a - 'a'][i].size();
         now -= mi[a - 'a'][i];
         if ( now >= p )
         {
              find2(i, p - t, a);
              break;
         }
     }    
     return; 
}
int main()
{
    cin >> k >> str;
    list_make(k, str);
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        char a;
        int p;
        cin >> p >> a; 
        find(a, p);
    }
    for ( int q = 0; q < 30; q++ )
    {
        for ( int i = 0; i < k; i++ )
        {
            for ( int s = 0; s < mas[q][i].size(); s++ )
            {
                if ( mas[q][i][s] != -1 )
                {
                    rez[mas[q][i][s]] = q + 'a';
                }
            }
        }
    }
    for ( int i = 0; i < str.length() * k; i++ )
    {
        if ( rez[i] )
           cout << rez[i];
    }
    cin >> k;
    return 0;
}