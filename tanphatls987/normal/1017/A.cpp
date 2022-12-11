#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;

#define X first
#define Y second
const int N=1e3+10;
int n;
ii a[N];

bool comp(ii a,ii b){
        if (a.X==b.X) return a.Y<b.Y;
        return a.X>b.X;
}
int main(){
        cin>>n;
        for(int i=1;i<=n;i++){
                for(int j=0;j<=3;j++){
                        int val;
                        cin>>val;
                        a[i].X+=val;
                }
                a[i].Y=i;
        }
        sort(a+1,a+n+1,comp);
        int ans=1;
        while (a[ans].Y!=1) ans++;
        cout<<ans;
}