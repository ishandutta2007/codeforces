#include<bits/stdc++.h>

#define d(v) // printf("%i\n",v)

using namespace std;

int main()
{
    string s;
    cin>>s;
    //cout<<s<<"\n";
    int n=s.length();//exit(0);
    //printf("%i\n",n);
    d(n);
    if(n<26)
        return printf("-1"), 0;
    for(int i=0;i<n;i++)
        if(s[i]!='?')s[i]-='A';
    //cout<<s<<"\n";
    int a[26],k=0;
    memset(a,0,sizeof(a));
    for(int i=0;i<26;i++)
        if(s[i]!='?')
        {
            if(a[s[i]])
                k++;
            a[s[i]]++;
        }
    d(k);
    if(!k)
    {
        int j=0;
        for(int t=0;t<26;t++)
            if(s[t]=='?')
            {
                for(;a[j];j++);
                printf("%c",'A'+j);
                j++;
            }
            else
                printf("%c",'A'+s[t]);
        for(int t=26;t<n;t++)
            if(s[t]=='?')
                printf("A");
            else
                printf("%c",'A'+s[t]);
        return 0;
    }
    for(int i=26;i<n;i++)
    {
        if(s[i]!='?')
        {
            if(a[s[i]])
                k++;
            a[s[i]]++;
        }
        d(k);
        if(s[i-26]!='?')
        {
            a[s[i-26]]--;
            if(a[s[i-26]])
                k--;
        }
        d(k);
        //printf("%i .. %i - %i\n",i-24,i+1,k);
        if(!k)
        {
            for(int t=0;t<i-25;t++)
                if(s[t]=='?')
                    printf("A");
                else
                    printf("%c",'A'+s[t]);
            for(int j=0,t=i-25;t<=i;t++)
                if(s[t]=='?')
                {
                    for(;a[j];j++);
                    printf("%c",'A'+j);
                    j++;
                }
                else
                    printf("%c",'A'+s[t]);
            for(int t=i+1;t<n;t++)
                if(s[t]=='?')
                    printf("A");
                else
                    printf("%c",'A'+s[t]);
            return 0;
        }
    }
    printf("-1");
}/*
                                                 A?????????KLCSJB?????????Z
ABABABBAB????????????ABABABABA???????????ABABABABA?????????KLCSJB?????????Z
ABABABBABAAAAAAAAAAAAABABABABAAAAAAAAAAAAABABABABADEFGHIMNOKLCSJBPQRTUVWXYZ
*/