#include <bits/stdc++.h>
using namespace std;
string cccc(string x){
    string ans="";
    bool was=0;
    for(auto c:x){
        if(c!='0')was=1;
        if(was)ans+=c;
    }
    return ans;
}
int main(){
    string a,b;
    cin>>a>>b;
    a=cccc(a);
    b=cccc(b);
    if(a.length()<b.length())return 0*printf("<");
    if(a.length()>b.length())return 0*printf(">");
    if(a>b)printf(">");
    else if(a<b)printf("<");
    else printf("=");
    return 0;
}