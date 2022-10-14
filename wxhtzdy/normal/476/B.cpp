#include<bits/stdc++.h>
using namespace std;
int x=0,y=0,finalcnt=0;
void ccc(int c,int cnt,int n){
    if(cnt==n){
        if(c==x)finalcnt++;
        return;
    }
    ccc(c+1,cnt+1,n);
    ccc(c-1,cnt+1,n);
}
int main(){
    string a,b;
    cin>>a>>b;
    int n=(int)a.length(),cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]=='+')x++;
        else x--;
    }
    for(int i=0;i<n;i++){
        if(b[i]=='+')y++;
        if(b[i]=='-')y--;
        if(b[i]=='?')cnt++;
    }
    ccc(y,0,cnt);
    printf("%.12lf",1.0*(double)finalcnt/(double)pow(2,cnt));
}