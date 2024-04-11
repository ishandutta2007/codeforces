#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define mp make_pair
#define pb push_back
#define INF 1000000000
#define MAXT 1000000

using namespace std;

int n,p2[10],p3[10];
long long a[10];
int f[10][10][6666],g[10][444],ans,OR[6666][444],r32[6666],cost[MAXT+10],prime[MAXT+10],kA[10],s[444];

int bit2(int mask,int x){return (mask>>x)%2;}
int bit3(int mask,int x){return (mask/p3[x])%3;}
void set2(int &mask,int x,int val){
    if (val==1)
        mask|=p2[x];
    else mask&=(p2[n]-1-p2[x]);
}
void set3(int &mask,int x,int val){
    mask=((mask/p3[x+1])*3+val)*p3[x]+(mask%p3[x]);
}

void upd(int i,int j,int mask,int val){
    if (j==n){
        int x=r32[mask];
        if ((g[i][x]==-1)||(val<g[i][x]))g[i][x]=val;
        return;
    }
    if ((f[i][j][mask]==-1)||(val<f[i][j][mask]))f[i][j][mask]=val;
}

long long gcd(long long x,long long y){
    while ((x>0)&&(y>0))
        if (x>y)x%=y;else y%=x;
    return x+y;
}

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    
    p3[0]=1;for (int i=1;i<=n;i++)p3[i]=p3[i-1]*3;
    p2[0]=1;for (int i=1;i<=n;i++)p2[i]=p2[i-1]*2;
    
    s[0]=0;
    for (int i=1;i<p2[n];i++)s[i]=INF;
    
    for (int i=1;i<=MAXT;i++)prime[i]=i;
    for (int i=2;i<=MAXT;i++)
        if (prime[i]==i)
            for (int j=i+i;j<=MAXT;j+=i)prime[j]=i;
    cost[1]=0;
    for (int i=2;i<=MAXT;i++)cost[i]=cost[i/prime[i]]+1;
    
    
    for (int mask=0;mask<p3[n];mask++){
        int m2=0;
        for (int i=0;i<n;i++)
            if (bit3(mask,i)!=0)set2(m2,i,1);
        r32[mask]=m2;
    }
    
    for (int mask1=0;mask1<p3[n];mask1++)
        for (int mask2=0;mask2<p2[n];mask2++){
            int newmask=mask1;
            for (int i=0;i<n;i++)
                if ((bit2(mask2,i)!=0)&&(bit3(newmask,i)==0))set3(newmask,i,1);
            OR[mask1][mask2]=newmask;
        }
    
    for (int i=0;i<n;i++){
        long long x=a[i];
        int kr=0;
        for (long long t=2;t*t<=a[i];t++)
            while (x%t==0){
                x/=t;
                kr++;
            }
        if (x!=1)kr++;
        kA[i]=kr;
    }
    
    memset(f,-1,sizeof(f));
    memset(g,-1,sizeof(g));
    for (int i=0;i<n;i++){
        if (kA[i]==1){
            g[i][1<<i]=1;
            continue;
        }
        for (int mask=0;mask<p2[n];mask++){
            if ((mask&(1<<i))!=0)continue;
            long long x=a[i];
            int m2=0;
            for (int j=0;j<n;j++)
                if (bit2(mask,j)==1){
                    set3(m2,j,2);
                    if (x%a[j]!=0){x=-1;break;}
                    x/=a[j];
                }
            if (x<0)continue;
            set3(m2,i,1);
            int kr;
            if (x<=MAXT)
                kr=cost[x];
            else kr=kA[i]-cost[a[i]/x];
            f[i][0][m2]=kr+1;
        }
        for (int j=0;j<n;j++)
            for (int mask=0;mask<p3[n];mask++)
                if (f[i][j][mask]!=-1){
                    if (bit3(mask,j)!=2){
                        upd(i,j+1,mask,f[i][j][mask]);
                        continue;
                    }
                    for (int mask2=0;mask2<p2[n];mask2++)
                        if (g[j][mask2]!=-1)
                            upd(i,j+1,OR[mask][mask2],f[i][j][mask]+g[j][mask2]);
                }
    }
    ans=INF;
    for (int i=0;i<n;i++)
        for (int mask=0;mask<p2[n];mask++)
            if (g[i][mask]!=-1){
                int cr=g[i][mask];
                for (int mask2=p2[n]-1;mask2>=0;mask2--)
                    if ((s[mask2]!=-1)&&(s[mask2]+g[i][mask]<s[mask2|mask]))
                        s[mask2|mask]=s[mask2]+g[i][mask];
            }
    long long x=1;
    for (int i=0;i<n-1;i++){
        if ((a[n-1]%x!=0)||(a[n-1]%a[i]!=0)){
            x=-1;
            break;
        }
        x=(x/gcd(x,a[i]))*a[i];
    }
    int ans=s[p2[n]-1]+1;
    if ((x>0)&&(g[n-1][p2[n]-1]!=-1)&&(g[n-1][p2[n]-1]<ans))ans=g[n-1][p2[n]-1];
    printf("%d\n",ans);
}