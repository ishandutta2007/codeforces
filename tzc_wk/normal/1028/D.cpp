#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
char s[20];
set<int> S;
int mx,mn;
int T,x;
int main() {
	cin>>T;
    S.insert(-1e9);
    S.insert(1e9);
    mx=1e9;
    mn=-1e9;
    int wt=1;
    int Ans=1;
    while(T--){
        scanf("%s", s);
        cin>>x;
        if(s[1] == 'D') {
            S.insert(x);
            if(mn < x && x < mx) ++ wt;
        }
        else{
            if(x<mn||x>mx){
                return puts("0"),0;
            }
            if(x!=mn&&x!=mx){
                Ans=Ans*2%MOD;
            } 
            wt=1;
            S.erase(x);
            set<int>::iterator it=S.lower_bound(x);
            mx=*it;
            mn=*(--it);
        }
    }
    printf("%d\n",1ll*Ans*wt%MOD);
}