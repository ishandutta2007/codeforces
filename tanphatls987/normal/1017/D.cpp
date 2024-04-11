#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;

#define X first
#define Y second

int n;
int h[1<<12],w[1<<12];
int f[1<<12][105];
int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int m,q;
        cin>>n>>m>>q;
        for(int i=0;i<n;i++) cin>>w[1<<i];
        for(int i=1;i<(1<<n);i++) w[i]=w[i&-i]+w[i^(i&-i)];
        while (m--){
                string s;
                cin>>s;
                int val=0;
                for(int j=0;j<n;j++) val=val*2+s[n-j-1]-'0';
                h[val]++;
        }
        for(int i=0;i<(1<<n);i++){
                for(int j=0;j<(1<<n);j++) {
                        int pos=((1<<n)-1)^i^j;
                        int cur=w[pos];
                        if (cur<=100) f[i][cur]+=h[j];
                }
                for(int j=1;j<=100;j++) f[i][j]+=f[i][j-1];
        }
        while (q--){
                string s;
                int x=0,k;
                cin>>s>>k;
                for(int j=0;j<n;j++) x=2*x+s[n-j-1]-'0';
                cout<<f[x][k]<<'\n';
        }
}