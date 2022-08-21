//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
using namespace std;
long long qzha[1500010],qzhb[1500010],m10[1500010];
int a,b,n;
char rp[1500010];
bool zc(int i)
{
    int cut=n-i;
    long long mod=m10[cut];
    return (qzhb[n]-qzhb[i-1]*mod%b)%b==0;
}
int main()
{
    cin>>rp>>a>>b;
    int n=strlen(rp);
    m10[0]=1;
    qzha[0]=qzhb[n+1]=0;
    for(int i=0;i<n;i++) qzha[i+1]=(qzha[i]*10%a+rp[i]-'0')%a;
    for(int i=1;i<=n+5;i++) m10[i]=(m10[i-1]*10)%b;
    for(int i=n-1;i>=0;i--) qzhb[i+1]=(qzhb[i+1+1]+m10[n-i-1]*(rp[i]-'0')%b)%b;
    for(int i=1;i<n;i++) //Note:  
    {
        if(qzha[i]==0&&qzhb[i+1]==0&&rp[i+1-1]!='0')
        {
            cout<<"YES\n";
            for(int j=1;j<=i;j++) putchar(rp[j-1]);
            cout<<"\n";
            for(int j=i+1;j<=n;j++) putchar(rp[j-1]);
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}