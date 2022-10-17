#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef pair<int,int> pii;
typedef long long ll;

int a[10005];
int main()
{
    int n;
    cin>>n;
    int cnt1=0,cnt2=0,k=n/2+(n%2?1:0);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]>0) cnt1++;
        if(a[i]<0) cnt2++;
    }
    if(cnt1>=k) cout<<1<<endl;
    else if(cnt2>=k) cout<<-1<<endl;
    else cout<<0<<endl;
}