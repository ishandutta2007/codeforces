#include <bits/stdc++.h>
using namespace std;
struct cmpp_int
{
    int co;
    int key;
};
cmpp_int num[1100];
int nag;
char s[110000];
int init;
bool cmp(cmpp_int x,cmpp_int y)
{
    return x.co<y.co;
}
int main()
{
    cin>>init>>s;
    nag=1;
    int cnt=1;
    int length=strlen(s);
    int now=0;
    int pre=-1;
    for(int i=1;i<=1000;i++)
        num[i].co=1;
    while(now<length)
    {
        if(s[now]=='-')
        {
            nag=-1;
            now++;
        }
        else if(s[now]=='*'||s[now]=='+')
            now++;
        else if(s[now]=='a')
        {
            if(now-2>pre&&s[now-1]=='+'&&s[now-2]=='+')
            {
                pre=now;
                num[cnt].co*=nag;
                num[cnt].key=0;
                cnt++;
                now++;
            }
            else
            {
                pre=now+2;
                num[cnt].co*=nag;
                num[cnt].key=1;
                cnt++;
                now+=3;
            }
            nag=1;
        }
        else
        {
            int sum=0;
            while(s[now]>='0'&&s[now]<='9')
            {
                sum=sum*10+(s[now]-'0');
                now++;
            }
            num[cnt].co=sum;
        }
    }
    cnt--;
    sort(num+1,num+1+cnt,cmp);
    int ans=0;
    for(int i=1; i<=cnt; i++)
    {
        if(!num[i].key)
        {
            init++;
            ans+=(num[i].co*init);
        }
        else
        {
            ans+=(num[i].co*init);
            init++;
        }
    }
    cout<<ans<<endl;
    return 0;
}