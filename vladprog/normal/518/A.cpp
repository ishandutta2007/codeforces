#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <map>
using namespace std;

int main() {
    string stuff= "abcdefghijklmnopqrstuvwxyz";
    map <char, int> tt;
    for (int i=0; i<26; i++){
        tt[stuff[i]]= i;

    }
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int n= t.length();
    for (int i= n-1; i>=0; i--){
        int j= tt[s[i]]+1;
        j= j%26;
        s[i]= stuff[j];
        if (tt[s[i]]!=0){
            break;
        }
    }
    bool check= 1;
    for (int i=0; i<n; i++){
        if (s[i]!=t[i]){
            check= 0;
            break;
        }
    }
    if (check==0){
        cout<<s<<endl;
    }
    else {
        cout<<"No such string"<<endl;
    }
    return 0;
}