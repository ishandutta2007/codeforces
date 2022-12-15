#include <bits/stdc++.h>
using namespace std;

const int MN = 5005, mod = 1e9+7;
int N, i, j, hsh[MN], pw[MN]={1}, c[MN][MN];
string s;

int getHsh(int x,int y){return hsh[y]-hsh[x-1]*pw[y-x+1];}

int main(){
    cin >> N >> s;
    s = s;
    for(i=1;i<=N;i++){
        hsh[i]=hsh[i-1]*131+s[i-1]-'0'+1;
        pw[i]=pw[i-1]*131;
    }
    c[2][1]=1;
    for(i=2;i<=N;i++){
        for(j=1;j<i;j++){
            c[i+1][j] = (c[i+1][j]+c[i][j])%mod;
            if(s[i-1]=='0') continue;
            int lo=0, hi=i-j-1, w;
            w = i+hi;
            while(lo<hi){
                int m=lo+hi>>1;
                if(getHsh(j,j+m)!=getHsh(i,i+m)) hi=m;
                else lo=m+1;
            }
            if(s[j+lo-1]>=s[i+lo-1]) w++;
            if(w<=N) c[w+1][i] = (c[w+1][i]+c[i][j])%mod;
        }
    }
    int ans = 0;
    for(i=1;i<=N;i++) ans=(ans+c[N+1][i])%mod;
    printf("%d\n",ans);
    return 0;
}