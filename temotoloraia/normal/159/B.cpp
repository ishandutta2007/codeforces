#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long n, m, mark[1002][1002], cap[1002][1002], i, j, v, u, a, b;
main(){
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a>>b;
        mark[a][b]++;
    }
    for(i=0;i<m;i++){
        cin>>a>>b;
        cap[a][b]++;
    }
    for(i=1;i<=1000;i++){
        for(j=1;j<=1000;j++){
            a=min(cap[i][j],mark[i][j]);
            cap[i][j]-=a;
            mark[i][j]-=a;
            v+=a;
        }
    }
    u=v;
    a=b=0;
    for(i=1;i<=1000;i++){
        for(j=1;j<=1000;j++){
            a+=cap[j][i];
            b+=mark[j][i];
        }
        u+=min(a,b);a=b=0;
    }
    cout<<u<<" "<<v<<endl;
}