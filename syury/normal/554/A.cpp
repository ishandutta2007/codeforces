#include<stdio.h>
#include<string>
#include<iostream>
#include<map>
#include<utility>

using namespace std;

map<string,int>mp;
int cnt=0;

int main(){
    string s;
    cin>>s;
    for(char c='a';c<='z';c++){
        string s1=c+s;
        if(!mp.count(s1)){mp.insert(make_pair(s1,1));cnt++;}
        s1=s+c;
        if(!mp.count(s1)){mp.insert(make_pair(s1,1));cnt++;}
    }
    int n=s.length();
    for(int i=0;i<n-1;i++){
        for(char j='a';j<='z';j++){
        string s1=s.substr(0,i+1)+j+s.substr(i+1,n-i);
        if(!mp.count(s1)){mp.insert(make_pair(s1,1));cnt++;}
        }
    }
    printf("%d",cnt);
    return 0;
}