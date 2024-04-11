#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
int main(){
    int n,k;
    scanf("%i%i",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int cnt=0;
    map<int,int> was;
    for(int i=0;i<n;i++){
        if(a[i]>k)break;
        cnt++;
        was[i]=1;
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]>k||was[i])break;
        cnt++;
    }
    printf("%i",cnt);
    return 0;
}