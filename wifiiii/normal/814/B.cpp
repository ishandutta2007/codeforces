#include<iostream>
#include<cstring>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))
#define scsz(s,a,b) for(int i=a,j=1;i<=b;++i){cout<<s[i];if(j++%10)cout<<"\n";else cout<<" ";}cout<<endl;
typedef long long ll;

int a[1005],b[1005],c[1005],res[1005],cnt=0;
vector<int> v;
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;++i) res[i]= 1;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
    for(int i=1;i<=n;++i) if(a[i]==b[i]&&res[a[i]]) c[i]=a[i],res[a[i]]=0;else {v.pb(i);cnt++;}
    if(cnt>2) while(1) cout<<1;
    if(cnt==2)
    {
        int i = v[0], j = v[1];
        if(!res[a[i]])
        {
            c[i] = b[i], c[j] = a[j];
        }
        else if(!res[b[i]])
        {
            c[i] = a[i], c[j] = b[j];
        }
        else
        {
           if(res[a[i]]&&res[b[j]])
                c[i] = a[i],c[j] = b[j];
            else c[i] = b[i], c[j] = a[j];
        }
    }
    else if(cnt==1)
    {
        int i = v[0];
        int j;
        for(int k=1;k<=n;++k) if(res[k]) {j=k;break;}
        c[i] = j;
    }
    for(int i=1;i<=n;++i) cout<<c[i]<<" ";
    cout<<endl;
}