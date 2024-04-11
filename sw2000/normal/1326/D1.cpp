#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;

char s[maxn],ss[maxn<<1];
int mnc[maxn<<1];

void manacher()
{
    int n=strlen(s+1),l=0;
    ss[l++]='#';
    ss[l++]='$';
    for(int i=1;i<=n;i++)
    {
        ss[l++]=s[i];
        ss[l++]='$';
    }
    ss[l]=0;

    int id,ma=0;
    for(int i=1;i<l;i++)
    {
        mnc[i]=ma>i?min(ma-i,mnc[id*2-i]):1;
        while(ss[i+mnc[i]]==ss[i-mnc[i]])mnc[i]++;

        if(mnc[i]+i>ma)
        {
            ma=mnc[i]+i;
            id=i;
        }
    }
//    for(int i=0;i<l;i++)cout<<ss[i];cout<<endl;
//    for(int i=0;i<l;i++)cout<<mnc[i];cout<<endl;
}

void solve()
{
    scanf("%s",s+1);
    manacher();
    int n=strlen(s+1);
    int l=0,r=n+1;
    while(s[l+1]==s[r-1])
    {
        l++;
        r--;
        if(l>=r)
        {
            printf("%s\n",s+1);
            return;
        }
    }
//    cout<<l<<' '<<r<<endl;
    int ml=0,mr=0;
    for(int i=l*2+1;i<r*2;i++)
    {
        if(i-mnc[i]<=l*2&&i<r+l)ml=max(ml,i-l*2-1);
        if(i+mnc[i]>=r*2&&i>r+l)mr=max(mr,r*2-i-1);
    }
    for(int i=1;i<=l;i++)printf("%c",s[i]);
    if(ml>mr)for(int i=l+1;i<=l+ml;i++)printf("%c",s[i]);
    else for(int i=r-mr;i<=r-1;i++)printf("%c",s[i]);
    for(int i=r;i<=n;i++)printf("%c",s[i]);
    puts("");
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        solve();
    }
}