#include <iostream>
#include <string>
using namespace std;
int mas[10000];
int in=0;
void tip ( string word, int ind )
{
    if ( word.length()>=4&&word.substr(word.length()-4, 4)=="lios" )
         mas[in]=1;
    else if ( word.length()>=5&&word.substr(word.length()-5, 5)=="liala" )
         mas[in]=2;
    else if ( word.length()>=3&&word.substr(word.length()-3, 3)=="etr" )
         mas[in]=3;
    else if ( word.length()>=4&&word.substr(word.length()-4, 4)=="etra" )
         mas[in]=4;
    else if ( word.length()>=6&&word.substr(word.length()-6, 6)=="initis" )
         mas[in]=5;
    else if ( word.length()>=6&&word.substr(word.length()-6, 6)=="inites" )
         mas[in]=6;
    else
        mas[in]=10;
}
void check( string str )
{
     string word="";
     for ( int i=0; i<str.length(); i++ )
     {
         if ( str[i]==' ' )
         {
                 tip(word, in);
                 in++;
                 word="";
         }
         else
             word+=str[i];
     }
     if ( word!="" )
     {
         tip(word, in);
         in++;
     }
}
void no ()
{
    cout << "NO";
    exit(0);
}
int main()
{
    string petr;
    getline(cin, petr);
    check(petr);
    if ( in==1 )
    {
        if ( mas[0]==10 )
            cout << "NO";
        else
            cout << "YES";
    }
    else
    {
        int woman=0, man=0;
        int sush=0, pril=0, glag=0;
        bool h=false, f=false, g=false;
        for ( int i=0; i<in; i++ )
        {
            if ( mas[i]==10 )
                no();
            if ( mas[i]%2==0 )
                man++;
            else 
                woman++;
            if ( (mas[i]-1)/2==0 )
                pril++;
            else if ( (mas[i]-1)/2==1 )
            {
                sush++;
                pril=0;
                if ( glag>0 )
                    no();
            }
            else if ( (mas[i]-1)/2==2 )
                glag++;

        }
        if ( sush==1&&pril==0&&(woman==0||man==0) )
            cout << "YES";
        else
            no();
    }
    return 0;
}
/*

lios etr initis lios aaainitis

*/