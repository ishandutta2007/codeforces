#include<bits/stdc++.h>
using namespace std;
string s;
bool a=0,b=0,ok=0;
int main(){
    cin>>s;
    int n=(int)s.length();
    for(int i=0;i<n-1;i++){
        if((i==0||(s[i-1]!='B'))&&(i==n-2||(s[i+2]!='A'))&&s[i]=='A'&&s[i+1]=='B')a=1;
        if((i==0||(s[i-1]!='A'))&&(i==n-2||(s[i+2]!='B'))&&s[i]=='B'&&s[i+1]=='A')b=1;
    }
    for(int i=0;i<n-1;i++){
        if(s[i]=='A'&&s[i+1]=='B'&&!a){a=1;i++;continue;}
        if(s[i]=='B'&&s[i+1]=='A'&&!b){b=1;i++;continue;}
    }

    if(a&&b)printf("YES");
    else printf("NO");
}