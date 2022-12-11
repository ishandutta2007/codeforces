#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int kk=n/3,op=n%3;
        if(op==0)for(int i=1;i<=kk;i++)printf("21");
        if(op==1){
            for(int i=1;i<=kk;i++)printf("12");
            printf("1");
        }
        if(op==2){
            for(int i=1;i<=kk;i++)printf("21");
            printf("2");
        }
        puts("");
    }
    return  0;
}