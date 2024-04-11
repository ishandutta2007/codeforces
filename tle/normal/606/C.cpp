#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int n,pos[200001],c,r;
inline void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&r);
        pos[r]=pos[r-1]+1;
        c=max(c,pos[r]);
    }
    cout<<n-c;
}
int main(){
    init();
    return 0;
}