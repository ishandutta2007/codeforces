#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        string s;
        cin>>s;
        int n=(int)s.size();
        int a=0,b=0,ans=0,opa=0,opb=0;
        bool wasa=0,wasb=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='('){
                wasa=1,a++,opa++;
                //if(a==0)ans++;
            }
            if(c==')'){
                wasa=1,a--;
                if(opa>0)ans++,opa--;
            }
            if(c=='['){
                wasb=1,b++,opb++;
                //if(b==0)ans++;
            }
            if(c==']'){
                wasb=1,b--;
                if(opb>0)ans++,opb--;
            }
        }
        printf("%i\n",ans);
    }
    return 0;
}