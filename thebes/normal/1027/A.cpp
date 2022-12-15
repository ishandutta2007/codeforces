#include <bits/stdc++.h>
using namespace std;

int N, T, i;
string s;
bool cmp(char a,char b){
    if(a<b) swap(a,b);
    if(a==b) return 1;
    else if(a-b==2) return 1;
    else return 0; 
}
int main(){
    for(scanf("%d",&T);T;T--){
        cin >> N >> s;
        bool can = true;
        for(i=0;i<s.size();i++){
            if(!cmp(s[i],s[s.size()-1-i])) can = false;
        }
        printf("%s\n",(can)?"YES":"NO");
    }
    return 0;
}