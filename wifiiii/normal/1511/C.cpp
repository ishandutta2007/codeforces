#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> first(50,-1),a(n);
    for(int i=0;i<n;++i) {
        cin>>a[i],--a[i];
        if(first[a[i]]==-1) first[a[i]]=i;
    }
    while(q--) {
        int x;
        cin>>x;
        --x;
        assert(first[x]!=-1);
        cout<<first[x]+1<<" ";
        for(int i=0;i<50;++i) {
            if(i!=x && first[i]!=-1 && first[i]<first[x]) first[i]+=1;
        }
        first[x]=0;
    }
}