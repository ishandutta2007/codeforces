#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n;
        scanf("%i",&n);
        int a[n],b[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        b[0]=a[0];for(int i=1;i<n;i++)b[i]=max(a[i],b[i-1]);
        int mx=0;
        for(int i=0;i<n;i++)ckmx(mx,b[i]-a[i]);
        int cnt=0;
        while(mx)cnt++,mx>>=1;
        printf("%i\n",cnt);
    }
    return 0;
}