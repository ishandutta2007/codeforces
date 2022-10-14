#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
char s[N],a[N];
vector<int> E[N];
int main(){
    scanf("%s",&s);
    int n=strlen(s),k;
    scanf("%i",&k);
    for(int i=0;i<k;i++){
        scanf("%s",&a);
        int l=strlen(a);
        for(int j=0;j<=n-l;j++){
            bool can=1;
            for(int t=0;t<l;t++)if(a[t]!=s[j+t])can=0;
            if(can)E[j+l-1].pb(j);
        }
    }
    int j=0,ans=0,id=0;
    for(int i=0;i<n;i++){
        while(true){
            if(j>=n)break;
            bool ok=1;
            for(int c:E[j])if(c>=i)ok=0;
            if(!ok)break;
            j++;
        }
        j--;
        if(j-i+1>ans)ans=j-i+1,id=i;
    }
    printf("%i %i",ans,id);
    return 0;
}