#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
const int N=200050;
const int M=2*N;
const int L=19;
char s[N];
pair<pair<int,int> ,int> tmp[N];
int id[N*2],sa[N],lcp[N],tot,rmq[N][L],logs[N];
void BuildSuffixArray()
{
    s[++tot]='a'+26;
    for(int i=1;i<=tot;i++) id[i]=s[i]-'a';
    for(int j=0;j<20;j++)
    {
        for(int i=1;i<=tot;i++) tmp[i]=mp(mp(id[i],id[i+(1<<j)]),i);
        sort(tmp+1,tmp+1+tot);
        int c=0;
        for(int i=1;i<=tot;i++)
        {
            id[tmp[i].second]=c+1;
            c+=tmp[i].first!=tmp[i+1].first;
        }
        if(c==tot) break;
    }
    for(int i=1;i<=tot;i++) sa[id[i]]=i;
}
void BuildLCPArray()
{
    int k=0;
    for(int i=1;i<=tot;i++)
    {
        if(id[i]==tot) continue;
        int j=sa[id[i]+1];
        while(i+k<=tot && j+k<=tot && s[i+k]==s[j+k]) k++;
        lcp[id[i]]=k;
        if(k) k--;
    }
}
void BuildSparseTable()
{
    for(int i=2;i<=tot;i++) logs[i]=logs[i>>1]+1;
    for(int i=1;i<tot;i++) rmq[i][0]=lcp[i];
    for(int j=1;j<L;j++)
    {
        for(int i=1;i<tot-(1<<j)+1;i++)
        {
            rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
        }
    }
}
int LCP(int l, int r)
{
    l=id[l];r=id[r];
    if(l==r) return tot-sa[l];
    if(l>r) swap(l,r);
    r--;
    int k=logs[r-l+1];
    return min(rmq[l][k],rmq[r-(1<<k)+1][k]);
}
bool comp(pair<int,int> i, pair<int,int> j){ return id[i.first]<id[j.first];}
int S[M],A[M],B[M];
int main()
{
    int n,q,i,x,y;
    scanf("%i %i",&n,&q);
    scanf("%s",s+1);tot=n;
    BuildSuffixArray();
    BuildLCPArray();
    BuildSparseTable();
    while(q--)
    {
        scanf("%i %i",&x,&y);
        vector<pair<int,int> > a;
        while(x--) scanf("%i",&i),a.pb(mp(i,0));
        while(y--) scanf("%i",&i),a.pb(mp(i,1));
        sort(a.begin(),a.end(),comp);
        ll suma=0,sumb=0,ans=0;
        int c=0;
        //if(a[0].second) suma=n-a[0].first+1,A[c]=1,B[c]=0;
        //else sumb=n-a[0].first+1,B[c]=1,A[c]=0;
        //S[c]=n-a[0].first+1;
        for(i=1;i<a.size();i++)
        {
            int tmp=LCP(a[i].first,a[i-1].first);
            //printf("(%i %i %i)\n",a[i].first,a[i].second,tmp);
            int asz=0,bsz=0;
            while(c && S[c]>=tmp)
            {
                suma-=(ll)A[c]*S[c];
                sumb-=(ll)B[c]*S[c];
                asz+=A[c];
                bsz+=B[c];
                c--;
            }
            suma+=(ll)asz*tmp;
            sumb+=(ll)bsz*tmp;
            S[++c]=tmp;
            A[c]=asz;
            B[c]=bsz;
            if(a[i-1].second)
            {
                A[c]++;
                suma+=tmp;
            }
            else
            {
                B[c]++;
                sumb+=tmp;
            }
            if(a[i].second)
            {
                ans+=sumb;
            }
            else
            {
                ans+=suma;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}