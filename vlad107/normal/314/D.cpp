#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <set>
#include <math.h>
#define N 500500
#define INF 10000000000LL
using namespace std;
int x[N],y[N];
long long minl[N],maxl[N],minr[N],maxr[N],ll,rr;
int n;
pair<long long,long long>a[N];
bool ok(long long M){
    int j=0;
    for (int i=0;i<n;i++){
        while ((j<n)&&(a[j].first-a[i].first<=M))j++;
        if (max((i>0)?maxl[i-1]:-INF,(j<n)?maxr[j]:-INF)-min((i>0)?minl[i-1]:INF,(j<n)?minr[j]:INF)<=M)return 1;
    }
    return 0;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
    for (int i=0;i<n;i++)a[i]=make_pair(x[i]-y[i],x[i]+y[i]);
    sort(a,a+n);
    for (int i=0;i<n;i++){
        minl[i]=min((i>0)?minl[i-1]:INF,a[i].second);
        maxl[i]=max((i>0)?maxl[i-1]:-INF,a[i].second);
    }
    for (int i=n-1;i>=0;i--){
        minr[i]=min((i+1<n)?minr[i+1]:INF,a[i].second);
        maxr[i]=max((i+1<n)?maxr[i+1]:-INF,a[i].second);
    }
    ll=0;rr=3e9;
    for (int it=0;it<40;it++)
        if (ok((ll+rr)/2))rr=(ll+rr)/2;else ll=(ll+rr)/2;
    if (!ok(ll))ll=rr;
    printf("%.10lf\n",ll*1.0/2);
}