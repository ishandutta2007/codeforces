#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 19;
ll n, i; double L[MN], R[MN], pw[MN]={1}, ans;
string l[MN], r[MN], s, t, idk;

void rec1(ll s,ll e,ll cnt,double tot){
    if(s == e){
        if(tot>=L[cnt]){
            l[cnt] = idk;
            L[cnt] = tot;
        }
    }
    else{
        int a = cnt+1, b = s-cnt+1;
        tot += (t[s]-'0')*pw[n-a]; idk.push_back('H');
        rec1(s+1, e, cnt+1, tot);
        tot -= (t[s]-'0')*pw[n-a]; idk.pop_back();
        tot += (t[s]-'0')*pw[n-b]; idk.push_back('M');
        rec1(s+1, e, cnt, tot);
        idk.pop_back();
    }
}

void rec2(ll s,ll e,ll cnt,double tot){
    if(s == e){
        if(tot>=R[cnt]){
            r[cnt] = idk;
            R[cnt] = tot;
        }
    }
    else{
        int a = cnt, b = 2*n-s-1-cnt;
        tot += (t[s]-'0')*pw[a]; idk.insert(idk.begin(),'H');
        rec2(s-1, e, cnt+1, tot);
        tot -= (t[s]-'0')*pw[a]; idk[0] = 'M';
        tot += (t[s]-'0')*pw[b];
        rec2(s-1, e, cnt, tot);
        idk.erase(idk.begin());
    }
}

int main(){
    for(i=1;i<MN;i++) pw[i]=pw[i-1]*10;
    scanf("%lld",&n); cin >> t;
    rec1(0, n, 0, 0);
    rec2(2*n-1,n-1,0,0);
    for(i=0;i<=n;i++){
        if(L[i]+R[n-i]>=ans){
            ans = L[i]+R[n-i];
            s = l[i]+r[n-i];
        }
    }
    printf("%s\n",s.c_str());
    return 0;
}