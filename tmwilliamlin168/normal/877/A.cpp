#include <bits/stdc++.h>

using namespace std;

const string f[] = {"Danil" , "Olya" , "Slava" , "Ann" , "Nikita" };

string str;

int main( int argc , char * argv[] ){
    cin >> str;
    int ok = 0;
    for(int i = 0 ; i < 5 ; ++ i){
        for(int j = 0 ; j + f[i].size() <= str.size() ; ++ j){
            string g = str.substr( j , f[i].size() );
            if( g == f[i] ) ++ ok;
        }
    }
    if( ok == 1 ) puts( "YES" );
    else puts( "NO" );
    return 0;
}