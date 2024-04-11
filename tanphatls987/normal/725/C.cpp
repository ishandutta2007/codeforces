#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned long long ull;

string s;
int h[26],ans[2][13];

ii a[100];
int main(){
//    freopen("input.inp","r",stdin);
    cin>>s;
    for(auto ch:s) h[ch-'A']++;
    int use=0;
    while (h[use]!=2) use++;
    int st=0,en=26;
    while (s[st]-'A'!=use) st++;
    while (s[en]-'A'!=use) en--;
    if (st+1==en){
        printf("Impossible");
        return 0;
    }
    for(int i=12;i>=0;i--) a[12-i]=ii(i,0);
    for(int i=0;i<=12;i++) a[13+i]=ii(i,1);
    for(int i=0;i<26;i++) a[26+i]=a[52+i]=a[i];
    int len=en-st;
    int pos=26+12-(len-1)/2;

//    cout<<len<<'\n';
//    cout<<pos-st<<'\n';
    for(int i=0,j=pos-st;i<27;i++) if (i!=en){
        ans[a[j].Y][a[j].X]=s[i]-'A';
        j++;
    }
    for(int j=0;j<=1;j++){
        for(int i=0;i<13;i++) printf("%c",char(ans[j][i]+'A'));
        printf("\n");
    }
}