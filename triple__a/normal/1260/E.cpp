#include<bits/stdc++.h>
using namespace std;

const int maxn=1<<19;
int n,a[maxn],idx;
priority_queue<int,vector<int>,greater<int> > pq;

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        if (a[i]==-1) idx=i;
    }
    long long ans=0;
    while (pq.size()) pq.pop();
    pq.push(a[n]);
    int l=n-1,r=n;
    while (r>idx){
//        cout<<pq.top()<<endl;
        ans+=pq.top();
        pq.pop();
        r>>=1;
        while (l>=r){
            pq.push(a[l]);
            l--;
        }
    }
    cout<<ans<<endl;
    return 0;
}