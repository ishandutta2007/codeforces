#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#define uint long long int
#define N 100005
using namespace std;
int d[N];
int s[N];
int maxpref[N];
int pref[N];
int main()
{
    ios_base::sync_with_stdio(0);
    int m, k;
    cin>>m>>k;
    for(int i=1; i<=m; i++)
    {
        cin>>d[i];
    }
    //int maxi=0;
    for(int i=1; i<=m; i++)
    {
        cin>>s[i];
        pref[i]=pref[i-1]+s[i];
        /* if(s[i]>maxi)
        {
            maxpref[i]=1;
        } */
    }
    maxpref[m+1]=1;
    s[m+1]=1005;
    int post=0;
    uint akt=0;
    int poz=1;
    int mini=0;
    int tmp;
    // akt=s[1];
    int maxi=s[1];
    int aktpost;
    for(int i=1; i<=m; i++)
    {
        akt+=s[i];
        akt-=d[i];
        if(s[i]>maxi)
        {
            maxi=s[i];
        }
        if(akt<0)
        {
            aktpost=(-akt+maxi-1)/maxi;
            akt+=aktpost*maxi;
            post+=k*aktpost;
        }
        
        post+=d[i];
           // post+=
    }
    cout<<post<<endl;
    // system("pause");
    
    /* while(poz<m+1)
    {
        mini=akt;
        tmp=akt;
        for(int i=poz; maxpref[poz]==0; poz++)
        {
            tmp= */
    return 0;
}