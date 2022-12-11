#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,ct[N];
int main(){
    scanf("%d\n",&t);
    while(t--){
        char a[N];
        scanf("%s",a);
        set<char>st;
        st.insert(a[0]);
        st.insert(a[1]);
        scanf("%s",a);
        st.insert(a[0]);
        st.insert(a[1]);
        printf("%d\n",st.size()==1?0:st.size()==2?1:st.size()==3?2:3);
    }
    return 0;
}