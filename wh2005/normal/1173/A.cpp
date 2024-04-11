#include<bits/stdc++.h>
using namespace std;
int x,y,z;


int main(){
    scanf("%d%d%d",&x,&y,&z);
    int p=x-y;
    if(abs(p)>z||z==0){
        if(p>0) printf("+\n");
        else if(p<0) printf("-\n");
        else printf("0\n");
    }
    else printf("?\n");
    return 0;
}