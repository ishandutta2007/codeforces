#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string a, b, c; cin >> a >> b >> c;
        int pa=0, pb=0, pc=0;
        string ans="";
        int ended=0;
        for (int i=1;i<=3*n;++i){
            // cout << pa << " " << pb << " " << pc << '\n';
            if (ended==1){
                if (pa>=max(pb,pc)) ans+=a[pa++];
                else if (pb>=max(pa,pc)) ans+=b[pb++];
                else ans+=c[pc++];
            }
            else if (ended==2) ans+="0";
            else{
                int curr=0;
                if (pa!=-1) curr+=a[pa]-'0';
                if (pb!=-1) curr+=b[pb]-'0';
                if (pc!=-1) curr+=c[pc]-'0';
                if (curr>=2) curr=1;
                else curr=0;
                ans+=((char)curr+'0');
                if (pa!=-1&&a[pa]-'0'==curr) pa++;
                if (pb!=-1&&b[pb]-'0'==curr) pb++;
                if (pc!=-1&&c[pc]-'0'==curr) pc++;
            }
            if (pa==a.size()) pa=-1;
            if (pb==b.size()) pb=-1;
            if (pc==c.size()) pc=-1;
            ended=(pa==-1)+(pb==-1)+(pc==-1);
        }
        cout << ans << '\n';
    }
}