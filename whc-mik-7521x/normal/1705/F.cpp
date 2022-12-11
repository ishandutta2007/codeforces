#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,ans1,ans2;
string s1,s2,ans;
int gt(string s){
    cout<<s<<endl;
    int res;
    fflush(stdout);
    scanf("%d",&res);
    if(res==n)exit(0);
    return res;
}
int main(){
    scanf("%d",&n);
    ans.resize(n);
    for(int i=1;i<=n;i++)s1+='T',s2+=(i&1)?'T':'F';
    ans1=gt(s1);
    ans2=gt(s2);
    int kk=n/3,ai=kk<<1;
    for(int i=0;i<kk;i++){
        s1[i<<1]=s1[i<<1|1]='F';
        int now=gt(s1);
        s1[i<<1]=s1[i<<1|1]='T';
        if(ans1-now==2){
            ans[i<<1]=ans[i<<1|1]='T';
        }
        else if(ans1-now==-2){
            ans[i<<1]=ans[i<<1|1]='F';
        }
        else{
            s2[i<<1]=s2[i<<1]=='F'?'T':'F';
            s2[i<<1|1]=s2[i<<1|1]=='F'?'T':'F';
            s2[ai]=s2[ai]=='F'?'T':'F';
            int pk=gt(s2);
            if(pk-ans2==1){//ac2 wa1
                ans[i<<1]=s2[i<<1];
                ans[i<<1|1]=s2[i<<1|1];
                ans[ai]=s2[ai]=='F'?'T':'F';
            }
            if(pk-ans2==3){//ac2 ac1
                ans[i<<1]=s2[i<<1];
                ans[i<<1|1]=s2[i<<1|1];
                ans[ai]=s2[ai];
            }
            if(pk-ans2==-1){//wa2 ac1
                ans[i<<1]=s2[i<<1]=='F'?'T':'F';
                ans[i<<1|1]=s2[i<<1|1]=='F'?'T':'F';
                ans[ai]=s2[ai];
            }
            if(pk-ans2==-3){//wa2 wa1
                ans[i<<1]=s2[i<<1]=='F'?'T':'F';
                ans[i<<1|1]=s2[i<<1|1]=='F'?'T':'F';
                ans[ai]=s2[ai]=='F'?'T':'F';
            }
            s2[i<<1]=s2[i<<1]=='F'?'T':'F';
            s2[i<<1|1]=s2[i<<1|1]=='F'?'T':'F';
            s2[ai]=s2[ai]=='F'?'T':'F';
            ai++;
        }
    }
    for(;ai<n;ai++){
        s1[ai]='F';
        int now=gt(s1);
        ans[ai]=(now-ans1>=0)?'F':'T';
        s1[ai]='T';
    }
    gt(ans);
    return 0;
}