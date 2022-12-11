#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int psum[2][N];
int trail[2][N];

char solve(int xa,int ya,int xb,int yb){

        int n1=psum[0][ya]-psum[0][xa-1];
        int n2=psum[1][yb]-psum[1][xb-1];
        int tr1=min(ya-xa+1,trail[0][ya]);
        int tr2=min(yb-xb+1,trail[1][yb]);
        
        if (n1>n2) return '0';
        if ((n1-n2)%2) return '0';
        
        if (tr1<tr2) return '0';
        if (n1==n2)
                return ('0'+(tr1%3==tr2%3));
        if (n1==0) return ('0'+(tr1>tr2));
        return '1';
}
int main(){
        string s[2];
        cin>>s[0]>>s[1];
        for(int cur=0;cur<=1;cur++)
                for(int j=0;j<s[cur].length();j++){
                        psum[cur][j+1]=psum[cur][j]+(s[cur][j]!='A');
                        if (s[cur][j]=='A') trail[cur][j+1]=trail[cur][j]+1;
                        else trail[cur][j+1]=0;
                }
        int test;
        cin>>test;
        while (test--){
                int xa,ya,xb,yb;
                cin>>xa>>ya>>xb>>yb;
                cout<<solve(xa,ya,xb,yb);
        }
}