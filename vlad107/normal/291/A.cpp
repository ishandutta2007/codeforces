#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <map>
using namespace std;
int n,x,res;
map<int,int>a;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&x);
        if (x)a[x]++;
    }
    for (map<int,int>::iterator it=a.begin();it!=a.end();it++){
        if (it->second>2){puts("-1");return 0;}
        res+=(it->second==2);
    }
    printf("%d\n",res);
}