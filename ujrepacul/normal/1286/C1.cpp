#include <bits/stdc++.h>
using namespace std;
char rz[103];
long long fv[20000][30];
long long fv1[20000][30];
char vc[103];
vector <long long> vi[103];
vector <long long> vi1[103];
const long long mod=3129401324902LL;
long long fvc[103];
long long hsh(long long pz,long long care)
{
    long long rz=1;
    if(care==1)
    {
        for(long long i=1;i<=26;++i)
            rz=(rz*1LL*(fv[pz][i]+3123LL)+4132LL)%mod;
        return rz;
    }
    else
    {
        for(long long i=1;i<=26;++i)
            rz=(rz*1LL*(fv1[pz][i]+3123LL)+4132LL)%mod;
        return rz;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long root,m,n,w,t,i,j,k=0,pas=1<<15,sc=0,cnt=0,mn=1000000009,nr1=0,nr2=0;
    cin>>n;
    cout<<"? "<<1<<' '<<n<<'\n';
    for(i=1;i<=n*(n+1)/2;++i)
    {
        cin>>vc;
        long long lc=strlen(vc);
        for(j=0;j<lc;++j)
            ++fv[i][vc[j]-'a'+1];
        vi[lc].push_back(i);
    }
    cout.flush();
    if(n==1)
    {
        for(j=1;j<=26;++j)
        {
            if(fv[1][j]!=0)
            {
                cout<<"! "<<(char)('a'+j-1);
                return 0;
            }
        }
    }
    cout<<"? "<<2<<' '<<n<<'\n';
    for(i=1;i<=n*(n-1)/2;++i)
    {
        cin>>vc;
        long long lc=strlen(vc);
        for(j=0;j<lc;++j)
            ++fv1[i][vc[j]-'a'+1];
        vi1[lc].push_back(i);
    }
    cout.flush();
    for(i=1;i<=n;++i)
    {
        long long cur=0;
        for(j=0;j<vi[i].size();++j)
            cur=(long long)cur^hsh(vi[i][j],1);
        for(j=0;j<vi1[i].size();++j)
            cur=(long long)cur^hsh(vi1[i][j],2);
        for(j=0;j<vi[i].size();++j)
            if(hsh(vi[i][j],1)==cur)
                break;
        long long cj=j;
        for(j=1;j<=26;++j)
            fvc[j]=fv[vi[i][cj]][j];
        for(j=1;j<i;++j)
            --fvc[rz[j]-'a'+1];
        for(j=1;j<=26;++j)
        {
            if(fvc[j]!=0)
            {
                rz[i]='a'+j-1;
                break;
            }
        }
    }
    cout<<"! "<<(rz+1)<<'\n';
    cout.flush();
    return 0;
}