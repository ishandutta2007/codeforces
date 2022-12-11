#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N],t;
int main() {
    cin>>t;
    for(;t--;){
        cin>>n;
        for(int i = 1; i <= n; ++i)cin>>a[i];
        int l=1,r=n,ans=0;
        while(l<=r){
            for(;l<=r&&!a[l];l++);
            for(;l<=r&&a[r];r--);
            if(l>r)break;
            ans++;
            a[l]--,a[r]++;
        }
        cout<<ans<<endl;
    }
	return 0;
}