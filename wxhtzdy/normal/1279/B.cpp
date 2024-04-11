#include <bits/stdc++.h>
using namespace std;

const int N=100050;
int a[N];

void solve(){
    int n,s;scanf("%i%i",&n,&s);
    long long S=0;
    for(int i=1;i<=n;i++)scanf("%i",&a[i]),S+=a[i];
    if(S<=s){printf("0\n");return;}
    int mx=0;
    S=0;
    for(int i=1;i<=n;i++){
        S+=a[i];
        if(a[i]>a[mx])mx=i;
        if(S>s){
            printf("%i\n",mx);
            return;
        }
    }
}

int main(){
    int t;scanf("%i",&t);
    while(t--)
        solve();
    return 0;
}