#include <bits/stdc++.h>
using namespace std;

const int MN = 3e5+5, LG = 22;
int f[MN][LG], s[MN][LG], n, a[MN], i, j, p, l, r, ans;
vector<int> vec;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        f[i][0]=s[i][0]=a[i];
    for(j=1;j<LG;j++){
        for(i=1;i<=n;i++){
            if(i+(1<<j)-1<=n) f[i][j]=__gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
            else f[i][j]=-1;
            if(i-(1<<j)+1>=1) s[i][j]=__gcd(s[i][j-1],s[i-(1<<(j-1))][j-1]);
            else s[i][j]=-1;
        }
    }
    for(i=1;i<=n;i++){
        p = i;
        for(j=LG-1;j>=0;j--){
            if(f[p][j]!=-1&&f[p][j]%a[i]==0) p += (1<<j);
            if(p>n) break;
        }
        p = min(p, n+1);
        l = p-i-1;
        p = i;
        for(j=LG-1;j>=0;j--){
            if(s[p][j]!=-1&&s[p][j]%a[i]==0) p -= (1<<j);
            if(p<1) break;
        }
        p = max(p, 0);
        r = i-p-1;
        int tmp = l+r;
        if(tmp>ans){
            vec.clear(); vec.push_back(p+1);
            ans = tmp;
        }
        else if(tmp==ans){
            if(!(vec.size()&&vec.back()==p+1))vec.push_back(p+1);
        }
    }
    printf("%d %d\n",vec.size(),ans);
    for(auto v : vec) printf("%d ",v);
    return 0;
}