#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
string aa,bb;
//0 1 2
int score[4][4];
int sb[1001][1001];
int main()
{
    score[0][0]=0; score[0][1]=0;score[0][2]=1;
    score[1][0]=1; score[1][1]=0; score[1][2]=0;
    score[2][0]=0;score[2][1]=1; score[2][2]=0;
    sb['8']['<']=0;
    sb['('][')']=1;
    sb['['][']']=2;
    cin>>aa>>bb;
    int ll=aa.length(),p1=0,p2=0;
    for(int i=0;i<ll;i+=2)
    {
        int ys1=sb[aa[i]][aa[i+1]],ys2=sb[bb[i]][bb[i+1]];
        p1+=score[ys1][ys2]; p2+=score[ys2][ys1];
    }
    if(p1>p2) cout<<"TEAM 1 WINS";
    else if(p1==p2)cout<<"TIE";
    else cout<<"TEAM 2 WINS";
}