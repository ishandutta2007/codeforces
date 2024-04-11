#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int N=1e5+10;


int n;
vector <int> a[N];


int q[N<<1];

vector <int> operator -(vector <int> a,vector <int> b){
    int n=a.size();
    for(int i=0;i<n;i++) a[i]-=b[i];
    return a;
}
ll operator *(vector <int> a,vector <int> b){
    int n=a.size();
    ll ans=0;
    for(int i=0;i<n;i++) ans+=a[i]*b[i];
    return ans;
}

int check(int v1,int v2,int v3){
    vector <int> p1=a[v2]-a[v1],p2=a[v3]-a[v2],p3=a[v1]-a[v3];
    ll len1=p1*p1,len2=p2*p2,len3=p3*p3;
    if (len1>=len2+len3) return v3;
    if (len2>=len1+len3) return v1;
    if (len3>=len1+len2) return v2;
    return -1;
}
void solve(){
    for(int i=1;i<=n;i++) q[i]=i;
    int top=1,bot=n;
    while (bot-top+1>=3){
        int winner=check(q[top],q[top+1],q[top+2]);
        top+=3;
        if (winner!=-1) q[++bot]=winner;
    }
//    cout<<top<<" "<<bot<<'\n';
    vector <int> ans;
    for(int i=top;i<=bot;i++){
        int cur=q[i];

        bool okay=1;
        for(int v1=1;v1<=n;v1++) if (v1!=cur)
            for(int v2=v1+1;v2<=n&&okay;v2++) if (v2!=cur)
                if (check(cur,v1,v2)!=cur) okay=0;
        if (okay) ans.push_back(cur);
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans) cout<<i<<" ";
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=0,val;j<5;j++){
            scanf("%d",&val);
            a[i].push_back(val);
        }

    solve();
}