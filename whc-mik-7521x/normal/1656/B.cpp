#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],n,t,k;
long long sum;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        set<int>st;
        int pd=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(st.find(x+k)!=st.end()||st.find(x-k)!=st.end())pd=1;
            st.insert(x);
        }
        puts(pd?"YES":"NO");
    }
    return  0;
}