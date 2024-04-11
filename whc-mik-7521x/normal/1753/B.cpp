#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,x,ct[N];
int main(){
    scanf("%d%d",&n,&x);
    for(int i=1,o;i<=n;i++)scanf("%d",&o),ct[o]++;
    for(int i=1;i<=x+1;i++){
        if(ct[i]%(i+1)!=0||i>=x){puts(x<=i?"Yes":"No");break;}
        ct[i+1]+=ct[i]/(i+1);
    }
    return 0;
}