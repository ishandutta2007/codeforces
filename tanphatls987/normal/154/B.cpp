#include <bits/stdc++.h>

using namespace std;

const int alp=27;
const int N=1e5+10;

int n,m;
int t[N];
int h[N],cur[N];

void prepare(){
    cin>>n>>m;
    for(int i=2;i<=n;i++) if (!t[i])
        for(int j=i;j<=n;j+=i) t[j]=i;
}
int check(int x,int type){
    int mask=x;
    while (x>1){
        if (type==0&&cur[t[x]]) return cur[t[x]];
        if (type==1) cur[t[x]]=mask;
        if (type==2) cur[t[x]]=0;
        x/=t[x];
    }
    return -1;
}
int main(){
    prepare();
    while (m--){
        char ch;
        int x;
        cin>>ch>>x;
        if (ch=='+'){
            int ans=check(x,0);
            if (h[x]){
                cout<<"Already on\n";
                continue;
            }
            if (ans!=-1) {
                cout<<"Conflict with "<<ans<<'\n';
                continue;
            }
            cout<<"Success\n";
            check(x,1);
            h[x]=1;
            continue;
        }
        if (!h[x]){
            cout<<"Already off\n";
            continue;
        }
        cout<<"Success\n";
        check(x,2);
        h[x]=0;
    }
}