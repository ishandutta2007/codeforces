#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9+7;
const int N = 3e3+9;
const int S = 1e2+9;
int T,n;ll f[S][N];
char s[N];

int main(){
    f[0][0]=1;
    for(int i=1;i<=S-9;i++)
        for(int j=0;j<=(i-1)*25;j++){
            for(int k=0;k<=25;k++)
                (f[i][j+k]+=f[i-1][j])%=mod;
        }
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);n=strlen(s);int sum=0;
        for(int i=0;i<n;i++) sum+=s[i]-'a';
        printf("%lld\n",((f[n][sum]-1)%mod+mod)%mod);
    }
    return 0;
}
/*
g++ CF156C.cpp -o A
*/