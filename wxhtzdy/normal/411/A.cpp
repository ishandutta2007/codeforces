#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    if(s.length()<5){
        cout<<"Too weak";
        return 0;
    }
    bool ok=0;
    for(char c:s)if(c>='a'&&c<='z')ok=1;
    if(!ok){
        cout<<"Too weak";
        return 0;
    }
    ok=0;
    for(char c:s)if(c>='A'&&c<='Z')ok=1;
    if(!ok){
        cout<<"Too weak";
        return 0;
    }
    ok=0;
    for(char c:s)if(c>='0'&&c<='9')ok=1;
    if(!ok){
        cout<<"Too weak";
        return 0;
    }
    cout<<"Correct";
    return 0;
}