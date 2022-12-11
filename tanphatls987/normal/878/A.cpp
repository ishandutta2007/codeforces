#include <bits/stdc++.h>

using namespace std;


int cur[10][2],ans[3];
int do_op(int x,int y,int type){
    if (type=='|') return x|y;
    if (type=='^') return x^y;
    if (type=='&') return x&y;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<10;i++)
        for(int j=0;j<=1;j++) cur[i][j]=j;
    while (n--){
        char type;
        int val;
        cin>>type>>val;
        for(int i=0;i<10;i++,val>>=1)
            for(int j=0;j<=1;j++) cur[i][j]=do_op(cur[i][j],val&1,type);
    }
    /// & -> | -> ^
    for(int i=0;i<10;i++){
        if (cur[i][0]!=cur[i][1]){
            ans[0]|=1<<i;
            ans[2]|=cur[i][0]<<i;
        }else if (cur[i][0]==1) ans[1]|=1<<i;
    }
    cout<<"3\n& "<<ans[0]<<"\n| "<<ans[1]<<"\n^ "<<ans[2];
}