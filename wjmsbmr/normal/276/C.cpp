#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 1000010
int n,m,a[N],s[N],b[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0,x,y;i<m;i++)
        scanf("%d%d",&x,&y),s[x-1]++,s[y]--;
    for(int i=0,w=0;i<n;i++)
        w+=s[i],b[i]=w;
    sort(b,b+n);
    ll S=0;
    for(int i=0;i<n;i++)S+=(ll)a[i]*b[i];
    cout<<S<<endl;
    return 0;
}