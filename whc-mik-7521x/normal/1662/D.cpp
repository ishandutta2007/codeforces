#include<bits/stdc++.h>
using namespace std;
int t;
string s1,s2;
bool isAA(string s){
    return s=="AA";
}
bool isBB(string s){
    return s=="BB";
}
bool isBA(string s){
    return s=="BA";
}
bool isCB(string s){
    return s=="CB";
}
bool isCC(string s){
    return s=="CC";
}
bool check(string s){
    for(int i=0;i<(int)s.size();i++){
        if(s.size()-i>=2){
            if(isAA(s.substr(i,2)))return 1;
            if(isBB(s.substr(i,2)))return 1;
            if(isCC(s.substr(i,2)))return 1;
        }
    }
    return 0;
}
int fix(string &s){
    int res=0;
    for(int i=0;i<(int)s.size();i++){
        if(s.size()-i>=2){
            if(isBA(s.substr(i,2)))swap(s[i],s[i+1]),res++;
            if(isCB(s.substr(i,2)))swap(s[i],s[i+1]),res++;
        }
    }
    return res;
}
string calc(string s){
    string res;
    for(int i=0;i<(int)s.size();i++){
        int pd=0;
        if(s.size()-i>=2){
            if(isAA(s.substr(i,2)))pd=1,i++;
            else if(isBB(s.substr(i,2)))pd=1,i++;
            else if(isCC(s.substr(i,2)))pd=1,i++;
        }
        if(!pd)res+=s[i];
    }
    while(fix(res));
    return res;
}
string lst(string s){
    string res;
    for(char c:s)if(c!='B')res+=c;
    return res;
}
int ct(string s){
    int res=0;
    for(char c:s)res+=c=='B';
    return res%2;
}
int main(){
    scanf("%d",&t);
    while(t--){
        cin>>s1>>s2;
        s1=calc(s1);
        s2=calc(s2);
        while(fix(s1));
        while(fix(s2));
        while(check(s1))s1=calc(s1);
        while(check(s2))s2=calc(s2);
        puts(lst(s1)==lst(s2)&&ct(s1)==ct(s2)?"YES":"NO");
    }
    return  0;
}