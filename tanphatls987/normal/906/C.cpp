#include <bits/stdc++.h>

using namespace std;

const int N=22;


int n,m,con[1<<N];
int mask[N],smask[1<<N],t[1<<N],co[1<<N];
int main(){
        cin>>n>>m;
        if (m==n*(n-1)/2){
                cout<<"0";
                return 0;
        }
        for(int i=0;i<n;i++) mask[i]|=1<<i;
        while (m--){
                int x,y;
                cin>>x>>y;
                x--,y--;
                mask[x]|=1<<y;
                mask[y]|=1<<x;
        }
        for(int i=0;i<n;i++) {
                smask[1<<i]=mask[i];
                co[1<<i]=1;
                t[1<<i]=i+1;
        }

        int ans=n,stans=0;
        int bar=(1<<n)-1;
        for(int cur=0;cur<(1<<n);cur++){
                smask[cur]=smask[cur&-cur]|smask[cur^(cur&-cur)];
                co[cur]=co[cur&-cur]+co[cur^(cur&-cur)];
                if (t[cur]){
                        int ava=cur^smask[cur];
                        for(int x=0;x<n;x++) if ((1<<x)&ava)
                                t[cur|(1<<x)]=x+1;
                        
                        if (smask[cur]==bar){
                                int use=co[cur];
                                if (use<ans) ans=use,stans=cur;
                        }
                }
        }
        cout<<ans<<'\n';

        
        while (stans){
                cout<<t[stans]<<" ";
                stans^=1<<(t[stans]-1);
        } 
}