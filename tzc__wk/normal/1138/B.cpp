#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int n;
char c[maxn],a[maxn];
int A,B,C,D;
vector<int> t[2][2];
int x,y,z;
bool check(){
    for(x=0;x<=B;x++){
        for(z=0;z<=D;z++){
            y=x+z-D+z;
            if(y<0 || C-y<0) continue;
            if(x+(C-y)+z>n/2 || (B-x)+y+(D-z)>n/2) continue;
            if(n/2-(x+(C-y)+z) + n/2-((B-x)+y+(D-z)) == A)
                return 1;
        }
    }
    return 0;
}
int main(){
    cin>>n;
    scanf("%s",c+1);
    scanf("%s",a+1);
    A=B=C=D=0;
    t[0][0].clear(), t[1][0].clear(), t[0][1].clear(), t[1][1].clear();
    for(int i=1;i<=n;i++){
        if(c[i]=='0' && a[i]=='0') A++, t[0][0].push_back(i);
        if(c[i]=='1' && a[i]=='0') B++, t[1][0].push_back(i);
        if(c[i]=='0' && a[i]=='1') C++, t[0][1].push_back(i);
        if(c[i]=='1' && a[i]=='1') D++, t[1][1].push_back(i);
    }
    if(check()==0) cout<<"-1\n";
    else{
        for(int i=0;i<n/2-(x+(C-y)+z);i++) printf("%d ",t[0][0][i]);
        for(int i=0;i<x;i++) printf("%d ",t[1][0][i]);
        for(int i=0;i<C-y;i++) printf("%d ",t[0][1][i]);
        for(int i=0;i<z;i++) printf("%d ",t[1][1][i]);
    }
}