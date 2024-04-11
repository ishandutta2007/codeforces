#include<bits/stdc++.h>
using namespace std;
 
const int maxn=200007;
int n,m,ka,kb,deg[maxn];
vector<int> a,b;
priority_queue<int,vector<int>,greater<int> >la,lb;
int main(){
    scanf("%d%d%d%d",&n,&m,&ka,&kb);
    if (ka>=m||kb>=n){
        printf("No");
        return 0;
    }
    printf("Yes\n");
    for (int i=1;i<m;++i){
        if (i>ka) {a.push_back(1); continue;}
        int u;
        scanf("%d",&u);
        a.push_back(u);
    }
    for (int i=1;i<n;++i){
        if (i>kb) {b.push_back(n+m); continue;}
        int u;
        scanf("%d",&u);
        b.push_back(u);
    }
    for (auto c:a){
        deg[c]++;
    }
    for (auto c:b){
        deg[c]++;
    }
    for (int i=1;i<=n;++i){
        if (!deg[i]) la.push(i);
    }
    for (int i=1;i<=m;++i){
        if (!deg[i+n]) lb.push(i+n);
    }
    int j=0,k=0;
    for (int i=1;i<=n+m-2;++i){
        if (la.size()){
            printf("%d %d\n",la.top(),b[k]);
            deg[la.top()]--;
            la.pop();
            deg[b[k]]--;
            if (!deg[b[k]]) lb.push(b[k]);
            k++;
        }
        else{
            printf("%d %d\n",lb.top(),a[j]);
            deg[lb.top()]--;
            lb.pop();
            deg[a[j]]--;
            if (!deg[a[j]]) la.push(a[j]);
            j++;
        }
    }
    printf("%d %d\n",la.top(),lb.top());
    return 0;
}