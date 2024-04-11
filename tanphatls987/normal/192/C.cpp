#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define check() printf("tick\n")
using namespace std;

const int maxi=500001;
const int bar='a';
int op[26][26]={0};
char s[11];
int n,i,l,st,ed,j;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",s);
        l=strlen(s);
        st=s[0]-'a';ed=s[l-1]-'a';
        //printf("%d %d %d\n",st,ed,l);
        for(j=0;j<26;j++) if (op[j][st]||(j==st))
        {
                if (op[j][st]+l>op[j][ed]) op[j][ed]=op[j][st]+l;
        }
    }
    int ans=0;
    for(i=0;i<26;i++) if (ans<op[i][i]) ans=op[i][i];
    cout<<ans;
}