#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;

#define X first
#define Y second


int main(){
        int n;
        cin>>n;
        int ans=2*n+1,use=-1;
        for(int len=1;len<=n;len++){
                int rem=(n+len-1)/len;
                if (ans>rem+len){
                        ans=rem+len;
                        use=len;
                }
        }
        for(int en=n;en>0;en-=use){
                int st=max(1,en-use+1);
                for(int i=st;i<=en;i++) cout<<i<<" ";
        }
}