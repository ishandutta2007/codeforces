#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int n,m;
pair<int,int>a[500500];
int b[500500];
set<int> f;
set<pair<int,int> >p;

void rec(int x,int s,int k){
    if (!m)return;
    if (x>n)return;
    if (p.find(make_pair(x,s))!=p.end())return;
    p.insert(make_pair(x,s));
    if (s!=0&&f.find(s)==f.end()){
        printf("%d",k);
        for (int i=0;i<k;i++)printf(" %d",b[i]);
        puts("");
        --m;
        f.insert(s);
    }
    b[k]=a[x].first;
    rec(x+1,s+a[x].first,k+1);
    rec(x+1,s,k);
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a,a+n);
    rec(0,0,0);
}