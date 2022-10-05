#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
char s[maxn],ss[maxn];
vector<int> v[256];
long long ans=0;
main(){
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=m;i++)
        v[s[i]-'a'].push_back(i);
    while(n--){
        ans=0;
        scanf("%s",ss+1);
        int tmplen=strlen(ss+1);
        for(int i=1;i<=tmplen;i++){
            int tmp=0;
            if(i>m||ss[i]!=s[i]){
                int sub=ss[i]-'a';
                int pos=lower_bound(v[sub].begin(),v[sub].end(),i)-v[sub].begin();
                if(v[sub].size()==0) tmp=tmplen;
                else if(pos==v[sub].size()) tmp=i-v[sub][pos-1];
                else if(pos==0) tmp=v[sub][pos]-i;
                else	tmp=min(v[sub][pos]-i,i-v[sub][pos-1]);
                ans=ans+tmp;
            }
        }
        cout<<ans<<endl;
    }
}