#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
struct Square{
    int x,y;
};
int main(){
    string s1, s2;
    cin>>s1>>s2;
    Square a,b;
    a.x=(int)(s1[0]-'a'); a.y=(int)(s1[1]-'0');
    b.x=(int)(s2[0]-'a'); b.y=(int)(s2[1]-'0');
    string res[10001];
    int sz=0;
    while(a.x<b.x&&a.y<b.y)res[sz++]="RU",a.x++,a.y++;
    while(a.x>b.x&&a.y<b.y)res[sz++]="LU",a.x--,a.y++;
    while(a.x<b.x&&a.y>b.y)res[sz++]="RD",a.x++,a.y--;
    while(a.x>b.x&&a.y>b.y)res[sz++]="LD",a.x--,a.y--;
    while(a.x<b.x)res[sz++]="R",a.x++;
    while(a.x>b.x)res[sz++]="L",a.x--;
    while(a.y<b.y)res[sz++]="U",a.y++;
    while(a.y>b.y)res[sz++]="D",a.y--;
    cout<<sz<<endl;
    for(int i=0;i<sz;i++)cout<<res[i]<<endl;
    return 0;
}