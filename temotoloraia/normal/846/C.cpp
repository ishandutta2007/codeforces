#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=5005;
int n;
ll a[N];
ll s[N];
ll b[N],c[N];
int a0,a1,a2;
ll ans;
int main()
{
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
        s[i]=a[i];
        if (i)s[i]+=s[i-1];
    }
    c[n]=n;
    for (int i=n-1;i>=0;i--){
        b[i]=b[i+1];
        c[i]=c[i+1];
        if (s[n-1]-s[i-1]<b[i+1]){
            b[i]=s[n-1]-s[i-1];
            c[i]=i;
        }
    }
    a0=n;
    a1=n;
    a2=n;
    for (int l=0;l<n;l++)
        for (int r=l;r<n;r++){
            ll pas=b[r];
            if (r)pas+=s[r-1];
            if (l)pas-=s[l-1];
            if (pas<ans){
                ans=pas;
                a0=l;
                a1=r;
                a2=c[r];
            }
        }
    cout<<a0<<" "<<a1<<" "<<a2<<endl;
    return 0;
}