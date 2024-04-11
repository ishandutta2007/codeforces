#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
priority_queue<int>q;
int A[300010],B[300010];
int main(){
    int b,c,i,n,k,a;
    cin>>n;
    for(i=1;i<=n;i++) cin>>A[i]>>B[i];
    k=n;
    a=n;
    if(n==3){
    	 cout<<1<<" "<<2<<" "<<3;return 0;
    }
    while(k--){
        cout<<a<<" ";
        b=A[a];
        c=B[a];
        if(A[c]==b||B[c]==b){
            a=c;
        }
        else a=b;
    }

    return 0;

}