#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        char ss='9';
        for(int i=0;i<n;i++){
            ss=min(ss,s[i]);
        }
        if(n!=2)putchar(ss);
        else putchar(s[1]);
        puts("");
    }
    return  0;
}