#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,c[N],l[N];
map<int,int> f;
map<int,int>::iterator it;
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&l[i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) if(!f.count(l[i])) f[l[i]]=c[i];else f[l[i]]=min(f[l[i]],c[i]);
    for(int i=1;i<=n;i++){
        for(it=f.begin();it!=f.end();it++){
            if(it->first==l[i]) continue;
            int t=gcd(l[i],it->first);
            if(!f.count(t)) f[t]=it->second+c[i];
            else f[t]=min(f[t],it->second+c[i]);
        }
    }
    printf("%d\n",f[1]?f[1]:-1);
    return 0;
}