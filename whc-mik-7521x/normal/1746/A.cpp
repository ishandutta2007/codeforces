#include<bits/stdc++.h>
using namespace std;
int n,k;
int main() {
    int t;
    cin>>t;
    while (t--){
        cin>>n>>k;
        int pd=0,x;
        for(int i=1;i<=n;i++)cin>>x,pd|=x;
        puts(pd?"YES":"NO");
    }
	return 0;
}