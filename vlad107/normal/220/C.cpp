#include <stdio.h>
#include <algorithm>
#include <set>
#include <functional>

#define MAXN 500500
#define INF 1000000000

using namespace std;

multiset<int,greater<int> >s1;
multiset<int>s2;
int bs1,bs2,n,a[MAXN],b[MAXN],ct,nomb[MAXN],cr,noma[MAXN];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++){scanf("%d",&a[i]);noma[a[i]]=i;}
    for (int i=0;i<n;i++){scanf("%d",&b[i]);nomb[b[i]]=i;}
    s1.clear();s2.clear();
    bs1=0;bs2=0;
    for (int i=0;i<n;i++){
        ct=nomb[a[i]]-i;
        if (ct<=0)
            s1.insert(ct);
        else s2.insert(ct);
    }
    for (int i=0;i<n;i++){
        cr=INF;
        if (!s1.empty()){
            int qt=*s1.begin();
            cr=min(cr,(-(qt-bs1)));
        }
        if (!s2.empty())
            cr=min(cr,(*s2.begin())-bs2);
        printf("%d\n",cr);

        ct=0-noma[b[i]]+bs1;
        s1.erase(s1.find(ct));
        ct=n-1-noma[b[i]]+bs2+1;
        s2.insert(ct);
        bs1++;

        bs2++;
        while ((!s2.empty())&&(*s2.begin()==bs2)){
            s2.erase(s2.begin());
            s1.insert(0+bs1);
        }
    }
}