#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int a[200005];
int c[200005];
int main(){
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        s.insert(x);
    }
    for(int i=1;i<=n;i++){
        if(s.lower_bound(n-a[i])!=s.end()){
            c[i]=(a[i]+*(s.lower_bound(n-a[i])))%n;
            s.erase(s.lower_bound(n-a[i]));
        }
        else{
            c[i]=(a[i]+*(s.lower_bound(0)))%n;
            s.erase(s.lower_bound(0));
        }
    }
    for(int i=1;i<=n;i++)
        cout<<c[i]<<' '; 
    return 0;
}