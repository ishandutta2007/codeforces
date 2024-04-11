#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;
int n,m;
struct arr {
    int c,s,No;
} a[100000];
bool cmp(arr i,arr j) {
    return i.c>j.c;
}
vector<int> d[100000];
map<int,int> s;
map<int,int>::iterator it;
long long ans;
int g[100000],k,money,size;
bool go(int x) {
    vector<int>::iterator iter;
    for (iter=d[x].begin();iter!=d[x].end();++iter) {
        if (g[*iter]==x) continue;
        if (g[*iter]==-1||go(g[*iter])) {
            g[*iter]=x;
            return true;
        }
    } 
    return(false);
}
int main() {
    memset(g,255,sizeof(g));
    scanf("%d",&n);
    for (int i=0;i!=n;++i) {
        scanf("%d%d",&a[i].c,&a[i].s);
        a[i].No=i;
    }
    sort(a,a+n,cmp);
    for (int i=0;i!=n;++i) 
       s[a[i].s]=i;
    scanf("%d",&m);
    for (int i=0;i!=m;++i) {
        scanf("%d%d",&money,&size);
        if ((it=s.find(size+1))!=s.end()&&a[it->second].c<=money) 
            d[it->second].push_back(i);
        if ((it=s.find(size))!=s.end()&&a[it->second].c<=money) 
            d[it->second].push_back(i);  
    }   
    for (int i=0;i!=n;++i) 
        if (go(i)) {ans+=a[i].c;++k;}
    printf("%I64d\n%d\n",ans,k);
    for (int i=0;i!=m;++i)
      if (g[i]!=-1) printf("%d %d\n",i+1,a[g[i]].No+1); 
}