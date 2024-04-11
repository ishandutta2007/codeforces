#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int t,n,a[N],to[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int stk1[N],stk2[N],tp1=0,tp2=0;
        stk1[0]=stk2[0]=n+1;
        set<int>st1,st2;
        for(int i=n;i>=1;i--){
            to[i]=i+1;
            while(tp1&&a[stk1[tp1]]<a[i])st1.erase(st1.begin()),tp1--;
            stk1[++tp1]=i;st1.insert(i);
            while(tp2&&a[stk2[tp2]]>a[i])st2.erase(st2.begin()),tp2--;
            stk2[++tp2]=i;st2.insert(i);
            auto it=st1.lower_bound(stk2[tp2-1]);
            if(it!=st1.begin()){
                it--;
                to[i]=max(to[i],*it);
            }
            it=st2.lower_bound(stk1[tp1-1]);
            if(it!=st2.begin()){
                it--;
                to[i]=max(to[i],*it);
            }
        }
        int now=1,ans=0;
        while(now!=n)ans++,now=to[now];
        cout<<ans<<endl;
    }
    return  0;
}