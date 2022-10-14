#include <bits/stdc++.h>
using namespace std;

const int N=200222;
int n,q,f[N];
char s[N];
map<char,set<int>> pos;
void modify(int x,int v) {
        for(;x<N;x+=x&-x) f[x]+=v;
}
int query(int x) {
        int r=0;
        for(;x>0;x-=x&-x) r+=f[x];
        return r;
}
int walk(int x) {
        int p=0;
        for(int i=20;i>=0;i--) {
                int b=(1<<i);
                if (p+b<N&&f[p+b]<x) {
                     p+=b; x-=f[p];
                }
        }
        return p+1;
}
int main() {
        scanf("%d %d",&n,&q);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) {
                pos[s[i]].insert(i);
                modify(i,1);
        }
        while(q--) {
                int l,r;
                char cc;
                scanf("%d %d %c\n",&l,&r,&cc);
                l=walk(l);
                r=walk(r);
                while (1) {
                        auto it=pos[cc].lower_bound(l);
                        if (it==pos[cc].end()||*it>r) break;
                        modify(*it,-1);
                        pos[cc].erase(it);
                }
        }
        for(int i=1;i<=n;i++) if (query(i)!=query(i-1)) printf("%c",s[i]);
}