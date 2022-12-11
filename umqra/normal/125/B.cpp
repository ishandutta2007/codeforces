#include <iostream>
#include <string>
using namespace std;
void check ( string str )
{
    int h=-1;
    string teg="";
    bool close=false;
    for ( int i=0; i<str.length(); i++ )
    {
        teg+=str[i];
        if ( str[i]=='/' )
            close=true;
        if ( str[i]=='>' )
        {
            if ( close )
            {
                for ( int s=0; s<h; s++ )
                    cout << "  ";
                h--;
            }
            else
            {
                h++;
                for ( int s=0; s<h; s++ )
                    cout << "  ";
            }
            
            cout << teg << '\n';
            teg="";
            close=false;
        }
    }
}
int main()
{
    string xml;
    cin >> xml;
    check(xml);
   return 0; 
}