#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    scanf("%i",&n);
    int a[n],b[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]),b[i]=a[i];
    sort(b,b+n);
    ll pref1[n],pref2[n];
    for(int i=0;i<n;i++)pref1[i]=a[i]+(i==0?0:pref1[i-1]),pref2[i]=b[i]+(i==0?0:pref2[i-1]);
    int q;
    scanf("%i",&q);
    while(q--){
        int type,L,R;
        scanf("%i %i %i",&type,&L,&R);
        --L;--R;
        if(type==1)printf("%lld\n",pref1[R]-(L==0?0:pref1[L-1]));
        else printf("%lld\n",pref2[R]-(L==0?0:pref2[L-1]));
    }
}