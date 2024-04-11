#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin>>a;
    int n;
    scanf("%i",&n);
    bool ok=0;
    int cnt[2]={0,0};
    cnt[0]=cnt[1]=0;
    for(int i=0;i<n;i++){
        string c;
        cin>>c;
        if(c[0]==a[0]&&c[1]==a[1])ok=1;
        if(a[0]==c[1])cnt[0]=1;
        if(a[1]==c[0])cnt[1]=1;
    }
    if(cnt[0]>0&&cnt[1]>0)ok=1;
    if(ok)printf("YES");
    else printf("NO");
    return 0;
}