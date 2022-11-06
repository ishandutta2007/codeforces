#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

#define maxn 200010

int n, m;
int v1[maxn], v2[maxn];
string s1, s2;

void process(int a[])
{
    for(int i=a[0]; i>0; --i)
    {
        int j=i;

        while(a[j]==1 && a[j+1]==1)
        {
            a[j]=a[j+1]=0;
            a[j+2]=1;
            j+=2;
            a[0]=max(a[0], j);
        }
    }
}

int main()
{
    cin>>s1;
    cin>>s2;

    v1[0]=s1.size();

    for(int i=0; i<v1[0]; ++i)
        v1[v1[0]-i]=s1[i]-'0';

    v2[0]=s2.size();

    for(int i=0; i<v2[0]; ++i)
        v2[v2[0]-i]=s2[i]-'0';

    process(v1);
    process(v2);

    int nr=max(v1[0], v2[0]);

    for(int i=nr; i>0; --i)
    {
        if(v1[i]>v2[i])
        {
            printf(">\n");
            return 0;
        }
        if(v2[i]>v1[i])
        {
            printf("<\n");
            return 0;
        }
    }
    printf("=\n");

    return 0;
}