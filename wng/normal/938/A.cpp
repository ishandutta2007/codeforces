#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    set<char> v;
    v.insert('a');
    v.insert('e');
    v.insert('i');
    v.insert('o');
    v.insert('u');
    v.insert('y');
    string res="";
    bool lastisvow=false;
    for (auto c : s){
        bool isvow=(v.find(c)!=v.end());
        if (!lastisvow or !isvow){
                res+=c;
            }
        lastisvow=isvow;
    }
    cout<<res;
}