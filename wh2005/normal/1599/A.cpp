#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];char s[N];
bool tag1[N],tag2[N];
int L=0,R=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    scanf("%s",s+1),sort(a+1,a+1+n);
    for(int i=1;i<=n;++i) tag2[i]=(s[i]=='R'),L+=(i>1&&tag2[i]==tag2[i-1]);
    tag1[n]=tag2[n];for(int i=n-1;i>=1;--i) tag1[i]=(tag1[i+1]^1);
    R=L+1,printf("%d %c\n",a[R],tag1[R]?'R':'L'),R++;
    for(int i=2;i<=n;++i){
        if(tag1[R-1]^tag2[i]) printf("%d %c\n",a[R],tag1[R]?'R':'L'),R++;
        else printf("%d %c\n",a[L],tag1[L]?'R':'L'),L--;
    }
    return 0;
}