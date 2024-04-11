#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mp make_pair
const int N=2000050;
const int M=2*N;
int tot;char s[M];
int id[M],sa[M];
pair<pair<int,int> ,int> tmp[M];
void BuildSuffixArray()
{
    s[++tot]='('+2;
    int i,j;
    for(i=1;i<=tot;i++) id[i]=s[i]-'('+1;
    for(j=0;j<20;j++)
    {
        for(i=1;i<=tot;i++) tmp[i]=mp(mp(id[i],id[i+(1<<j)]),i);
        sort(tmp+1,tmp+1+tot);
        int c=0;
        for(i=1;i<=tot;i++)
        {
            id[tmp[i].second]=c+1;
            c+=tmp[i].first!=tmp[i+1].first;
        }
        if(c==tot) break;
    }
    for(i=1;i<=tot;i++) sa[id[i]]=i;
}
int p[N],m[N];
int main()
{
    int n,i;
    scanf("%s",s+1);
    n=strlen(s+1);
    for(i=1;i<=n;i++) s[i+n]=s[i];
    tot=n*2;
    BuildSuffixArray();
    for(i=1;i<=n;i++)
    {
        p[i]=p[i-1];
        if(s[i]=='(') p[i]++;
        else p[i]--;
    }
    m[n]=p[n];
    for(i=n-1;i>=1;i--)
    {
        m[i]=min(m[i+1],p[i]);
    }
    int sol=M,mn=M;
    int add=0;
    if(p[n]<0) add=-p[n];
    for(i=1;i<=n;i++)
    {
        if(mn-p[i-1]+p[n]+add>=0 && m[i]-p[i-1]+add>=0)
        {
            sol=min(sol,id[i]);
        }
        mn=min(mn,p[i]);
    }
    //printf("%i %i\n",sa[sol],sol);
    if(p[n]<0) for(i=0;i<-p[n];i++) printf("(");
    for(i=sa[sol];i<n+sa[sol];i++) printf("%c",s[i]);
    if(p[n]>0) for(i=0;i<p[n];i++) printf(")");
    printf("\n");
    return 0;
}