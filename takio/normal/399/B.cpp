#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int n,i;
    while(cin>>n)
    {
        long long res=0;
        char c;
        for(i=0;i<n;i++){
            cin>>c;
            if(c=='B')res|=1LL<<i;
        }
        cout<<res<<endl;
    }
}