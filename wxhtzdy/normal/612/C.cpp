#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
char s[N];
int main(){
    scanf("%s",&s);
    int n=strlen(s);
    deque<char> st;
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('||s[i]=='<'||s[i]=='{'||s[i]=='['){
            st.push_back(s[i]);
        }else{
            if(st.empty()){
                printf("Impossible");
                return 0;
            }else{
                char c=st[(int)st.size()-1];
                if((s[i]==')'&&c=='(')||(s[i]=='}'&&c=='{')||(s[i]=='>'&&c=='<')||(s[i]==']'&&c=='[')){
                    st.pop_back();
                }else{
                    ans++;
                    st.pop_back();
                }
            }
        }
    }
    if(!st.empty()){
         printf("Impossible");
         return 0;
    }
    printf("%i",ans);
    return 0;
}