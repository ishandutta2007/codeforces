#include<bits/stdc++.h>
using namespace std;
int n, m, k, i, j, l, r, c, t, fix[500][500];
char tbl[500][500];
void go(int r, int c){
    if(r>=n||r<0||c>=m||c<0||tbl[r][c]!='.'||fix[r][c])return;
    fix[r][c]=1;
    go(r+1,c);
    go(r-1,c);
    go(r,c+1);
    go(r,c-1);
    if(k){
        k--;
        tbl[r][c]='X';
    }
}
main(){
    cin>>n>>m>>k;
    for(i=0;i<n;i++){
        string s;
        cin>>s;
        for(j=0;j<m;j++){
            tbl[i][j]=s[j];
            if(tbl[i][j]=='.'){
                r=i;
                c=j;
            }
        }
    }
    go(r,c);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<tbl[i][j];
        }
    cout<<endl;
    }
}