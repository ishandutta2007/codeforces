#include <iostream>
#include <set>
#define uint long long int
#define P 777777777
#define N 77788
#define M 131072
using namespace std;
uint drz[2*M+5];
void aktu(int a, int war)
{
    //cout<<a<<" meh "<<war<<endl;
    a+=M;
    drz[a]=war;
    a/=2;
    while(a)
    {
        drz[a]=(drz[2*a]*drz[2*a+1])%P;
        a/=2;
    }
}
set<int>::iterator it;
uint pop[N];
uint nast[N];
uint akt[N];
uint dp[N][5][5];
uint good[5][5];
set<int> secik;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=2*M+2; i++)
    {
        drz[i]=1;
    }
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            cin>>good[i][j];
        }
    }
    dp[0][1][1]=1;
    dp[0][2][2]=1;
    dp[0][3][3]=1;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=3; j++)
        {
            for(int k=1; k<=3; k++)
            {
                for(int l=1; l<=3; l++)
                {
                    dp[i][j][k]+=dp[i-1][j][l]*good[l][k];
                    dp[i][j][k]%=P;
                }
            }
        }
    }
    /* for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            cout<<dp[n][i][j]<<" z"<<endl;
        }
    } */
    // cout<<dp[2][1][1]<<endl;
    uint wynpus=0;
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            wynpus+=dp[n-1][i][j];
        }
    }
    wynpus%=P;
    int ile=0;
    int v, t;
    secik.insert(0);
    secik.insert(n+1);
    int zm;
    // cout<<wynpus<<endl;
    for(int i=1; i<=m; i++)
    {
        cin>>v>>t;
        it=secik.lower_bound(v);
        it--;
        int zl=*it;
        int zp=*secik.upper_bound(v);
        // cout<<zl<<" "<<zp<<endl;
        zm=0;
        if(t==0)
        {
            zm--;
            secik.erase(v);
        }
        if(akt[v]==0)
        {
            zm++;
            if(t!=0)
            {
                secik.insert(v);
            }
        }
        ile+=zm;
        akt[v]=t;
        if(ile==0)
        {
            
            aktu(v, 1);
            cout<<wynpus<<endl;
            continue;
        }
        if(t!=0)
        {
            if(zl==0)
            {
                uint zia=0;
                for(int i=1; i<=3; i++)
                {
                    zia+=dp[v-1][i][t];
                }
                zia%=P;
                aktu(0, zia);
            }
            else
            {
                //cout<<"ziom"<<endl;
                aktu(zl, dp[v-zl][akt[zl]][t]);
            }
            if(zp==n+1)
            {
                uint zia=0;
                for(int i=1; i<=3; i++)
                {
                    zia+=dp[n-v][t][i];
                }
                zia%=P;
                aktu(v, zia);
            }
            else
            {
                //cout<<"tu"<<endl;
                //aktu(zl, dp[v-zl][akt[zl]][t]);
                aktu(v, dp[zp-v][t][akt[zp]]);
            }
        }
        else
        {
            aktu(v, 1);
            if(zl==0)
            {
                uint zia=0;
                for(int i=1; i<=3; i++)
                {
                    zia+=dp[zp-1][i][akt[zp]];
                }
                zia%=P;
                aktu(0, zia);
            }
            else
            {
                if(zp==n+1)
                {
                    uint zia=0;
                    for(int i=1; i<=3; i++)
                    {
                        zia+=dp[n-zl][akt[zl]][i];
                    }
                    zia%=P;
                    aktu(zl, zia);
                }
                else
                {
                    aktu(zl, dp[zp-zl][akt[zl]][akt[zp]]);
                }
            }
        }
        /* for(int i=1; i<=n; i++)
        {
            cout<<drz[i+M]<<" ";
        }
        cout<<"lol"<<endl; */
        cout<<drz[1]<<endl;
    }
    return 0;
}