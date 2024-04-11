#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
char name[1005][105];
int types[1005][15];
int type_num[1005];
char a[1005];
int type[15];
char names[1005];
map<string,int> ma;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%s",a);
        gets(a);
        //escape all the spaces
        int j;
        int sum=0;
        for (j=0;a[j]!='\0';j++)
        {
            if (a[j]==' ') continue;
            if (a[j]=='(') break;
            name[i][sum++]=a[j];
        }
        name[i][sum]='\0';
        for (j++;a[j]!='\0';j++)
        {
            if (a[j]==')') break;
            if (a[j]==' ') continue;
            if (a[j]=='T')
            {
                types[i][type_num[i]]=0;
                j++;
            }
            else if (a[j]=='s')
            {
                types[i][type_num[i]]=1;
                j+=6;
            }
            else if (a[j]=='i')
            {
                types[i][type_num[i]]=2;
                j+=3;
            }
            else if (a[j]=='d')
            {
                types[i][type_num[i]]=3;
                j+=6;
            }
            type_num[i]++;
            if (a[j]==')') break;
        }
    }
    int m;
    scanf("%d",&m);
    for (i=0;i<m;i++)
    {
        string a,b;
        cin>>a>>b;
        if (a=="string")
        {
            ma[b]=1;
        }
        else if (a=="int")
        {
            ma[b]=2;
        }
        else if (a=="double")
        {
            ma[b]=3;
        }
    }
    int k;
    scanf("%d",&k);
    gets(a);
    for (i=0;i<k;i++)
    {
        gets(a);
        //escape all the spaces
        int j;
        int sum=0;
        for (j=0;a[j]!='\0';j++)
        {
            if (a[j]==' ') continue;
            if (a[j]=='(') break;
            names[sum++]=a[j];
        }
        names[sum]='\0';
        sum=0;
        string b;
        b.resize(100);
        int tot=0;
        for (j++;a[j]!='\0';j++)
        {
            if (a[j]==' ') continue;
            if ((a[j]==',')||(a[j]==')'))
            {
                b.resize(tot);
                tot=0;
                type[sum]=ma[b];
                b.resize(100);
                sum++;
            }
            else
            {
                b[tot++]=a[j];
            }
            if (a[j]==')') break;
        }
        int ans=0;
        for (j=0;j<n;j++)
        {
            int k;
            for (k=0;;k++)
            {
                if (names[k]!=name[j][k]) break;
                if (names[k]=='\0') break;
            }
            if (names[k]!=name[j][k]) continue;
            if (type_num[j]!=sum) continue;
            for (k=0;k<sum;k++)
            {
                if (types[j][k]==0) continue;
                if (types[j][k]!=type[k]) break;
            }
            if (k==sum) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}