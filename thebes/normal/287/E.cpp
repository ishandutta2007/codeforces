#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6+6;
int n, arr[MN], a[MN], b[MN], m, i, x;
stack<int> st;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(scanf("%d",&m),i=1;i<=m;i++){
        scanf("%d",&x);
        b[x] = 1;
    }
    for(i=n;i>=1;i--){
        if(b[i]){
            st.push(a[i]);
            arr[i] = -a[i];
        }
        else{
            if(st.size()&&st.top()==a[i]){
                arr[i] = a[i];
                st.pop();
            }
            else{
                arr[i] = -a[i];
                st.push(a[i]);
            }
        }
    }
    if(st.empty()){
        printf("YES\n");
        for(i=1;i<=n;i++) printf("%d ",arr[i]);
    }
    else printf("NO\n");
    return 0;
}