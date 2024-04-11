#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <fstream>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <string>
#include <iomanip>

#define mp make_pair
#define pb push_back

using namespace std;

int ans,n,a[500500],b[500500];
map<int,int>mm;

void check(int x){
    int kt=0;
    for (int i=0;i<n;i++)
        if (a[i]==x)kt++;
    int qt=(n+1)/2;
    qt=qt-kt;
    if (qt<0)qt=0;
    if (ans==-1||(qt)<ans)ans=qt;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
        mm[a[i]]++;
        if (a[i]!=b[i])mm[b[i]]++;
    }
    ans=-1;
    for (int i=0;i<n;i++){
        if (mm[a[i]]*2>=n){
            check(a[i]);
            mm[a[i]]=0;
        }
        if (mm[b[i]]*2>=n){
            check(b[i]);
            mm[b[i]]=0;
        }
    }
    printf("%d\n",ans);
}