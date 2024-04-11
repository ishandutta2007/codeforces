#include <iostream>
#include <string>
using namespace std;
int letter[30];
int nado[30];
string str1, str2;
void check1 ( string str )
{
     for ( int i=0; i<str.length(); i++ )
         letter[(int)(str[i]-'a')]++;    
} 
void check2 ( int ind )
{
     for ( int i=0; i<ind; i++ )
     {
         if ( str1[i]!='?' )
         {
            nado[(int)(str1[i]-'a')]++;      
         }
     }
}
bool get ()
{
     for ( int i=0; i<30; i++ )
     {
         if ( nado[i]>letter[i] )
            return false;   
     }
     return true;
}
int main()
{
    int count=0;
    cin >> str1 >> str2;
    if ( str1.length()<str2.length() )
    {
         cout << 0;
         return 0;
    }
    check1(str2);
    check2(str2.length());
    count+=get();
    bool h=false;
    for ( int i=0; i<str1.length()-str2.length(); i++ )
    {
        if ( str1[i]!='?' )
           nado[(int)(str1[i]-'a')]--;
        if ( str1[i+str2.length()]!='?' )
           nado[(int)(str1[i+str2.length()]-'a')]++;
        count+=get();
    }
    cout << count;
    cin >> str1;
    return 0;
}