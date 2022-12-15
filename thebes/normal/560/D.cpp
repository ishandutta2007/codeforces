#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int hsh[MN][2], pw[MN]={1}, n, i, x, y;
string s, t;
int getHsh(int id,int x,int y){return hsh[y][id]-hsh[x-1][id]*pw[y-x+1];}

bool solve(int x,int y,int a,int b){
    if(getHsh(0,x,y)==getHsh(1,a,b)) return 1;
    if((y-x+1)&1) return 0;
    int i = x+y>>1, j = a+b>>1;
    if(solve(x,i,a,j)&&solve(i+1,y,j+1,b)) return 1;
    else if(solve(i+1,y,a,j)&&solve(x,i,j+1,b)) return 1;
    else return 0;
}

int main(){
    for(i=1;i<MN;i++) pw[i]=pw[i-1]*131;
    cin >> s >> t;
    n = s.size();
    for(i=1;i<=n;i++){
        hsh[i][0]=hsh[i-1][0]*131+s[i-1]-'a'+1;
        hsh[i][1]=hsh[i-1][1]*131+t[i-1]-'a'+1;
    }
    printf("%s\n",solve(1,n,1,n)?"YES":"NO");
    return 0;
}