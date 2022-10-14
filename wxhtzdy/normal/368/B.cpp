#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    scanf("%i%i",&n,&q);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    map<int,int> m;
    int cnt[n];
    cnt[n-1]=0;
    for(int i=n-1;i>=0;i--){
        if(i!=n-1)cnt[i]=cnt[i+1];
        if(m[a[i]]==0)cnt[i]++;
        m[a[i]]++;
    }
    for(int i=0;i<q;i++){
        int l;
        scanf("%i",&l);
        printf("%i\n",cnt[l-1]);
    }
}