#include <iostream>
#include <string>
using namespace std;
string stack[10000];
string check ( string str )
{
      int start=0, end=0;
      stack[end] = "/";
      string word = "";
      for ( int i = 1; i < str.length(); i++ )
      {
          if ( str[i] == '/' && word != "" )
          {
               if ( word != ".." )
               {
                  stack[end+1] = word;
                  end++;
               }
               else
                   end--;
               word = "";
          }
          else
              word+=str[i];
      } 
      if ( word != "" )
      {
           if ( word != ".." )
           {
                stack[end+1] = word;
                end++;
           }
           else
               end--;
      }
      string rez="";
      for ( int i=start; i<=end; i++ )
      {
          if ( stack[i] == "/" )
             rez += stack[i];
          else
             rez += stack[i] + '/';
      }
      return rez;
}
int main()
{
    string dir="/";
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        string com;
        cin >> com;
        if ( com == "pwd" )
           cout << dir << '\n';
        else
        {
            string put;
            cin >> put;
            if ( put[0] == '/' )
               dir = check(put);
            else
               dir = check(dir+put);
        }
    }
    return 0;
    
}