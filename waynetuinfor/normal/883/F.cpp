#include<bits/stdc++.h>
using namespace std;
set<string> st;
string proc(string &s){
    string nw="";
    for(char &c:s){
        if(c=='u')nw+="oo";
        else nw+=c;
    }
    s=nw; nw="";
    for(int i=s.size()-1;i>=0;--i){
        if(s[i]=='k' and nw.size() and nw[nw.size()-1]=='h')continue;
        else nw+=s[i];
    }
    return nw;
}
int main(){
    string str; cin>>str;
    while(cin>>str){
        st.insert(proc(str));
    }
    cout<<st.size()<<endl;
}