#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,l,r,pref[N];
void cl(int n){for(int i=0;i<n;i++)pref[i]=0;}
char s[N];
int main(){
    scanf("%s%i",&s,&m);
    n=strlen(s); cl(n);
    for(int i=0;i<n-1;i++){
        if(i>0)pref[i]+=pref[i-1];
        if(s[i]==s[i+1])pref[i]++;
    }
    for(int i=0;i<m;i++){
        scanf("%i%i",&l,&r);
        --l;--r;
        if(l==0)printf("%i\n",pref[r-1]);
        else printf("%i\n",pref[r-1]-pref[l-1]);
    }
}