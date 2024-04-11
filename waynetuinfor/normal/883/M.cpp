#include<bits/stdc++.h>
using namespace std;

bool dist(int x1,int y1,int x2,int y2){
    if(x1==x2 && (y1==y2+1 || y2==y1+1))return 1;
    if(y1==y2 && (x1==x2+1 || x2==x1+1))return 1;
    return 0;
}
int sameline(int x1,int y1,int x2,int y2){
    if(x1==x2)return 2*(2+abs(y1-y2)+1);
    if(y1==y2)return 2*(2+abs(x1-x2)+1);
    return 0;
}
int main(){
    int x1,y1,x2,y2,tmp; cin>>x1>>y1>>x2>>y2;
    if(dist(x1,y1,x2,y2)==1)cout<<8<<endl;
    else if(tmp=sameline(x1,y1,x2,y2))cout<<tmp<<endl;
    else cout<<2*(abs(x2-x1)+1+abs(y2-y1)+1)<<endl;
}