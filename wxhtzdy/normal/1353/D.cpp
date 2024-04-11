#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
struct cmp{
    bool operator() (const pii &a, const pii &b) const{
        int lena=a.second-a.first+1;
        int lenb=b.second-b.first+1;
        if(lena==lenb) return a.first<b.first;
        return lena>lenb;
    }
};
int main(){
    int T;
    scanf("%i",&T);
    while(T--){
        int n;
        scanf("%i",&n);
        set<pii,cmp> sg;
        sg.insert({1,n});
        int a[n+1],nxt=1;
        for(int i=1;i<=n;i++)a[i]=0;
        while(sg.size()){
            auto c=*sg.begin();
            int l=c.second-c.first+1;
            if(l%2==0){
                a[c.first+l/2-1]=nxt;
                nxt++;
                l/=2;
                sg.erase(sg.begin());
                if(l>1)sg.insert({c.first,c.first+l-2});
                if(c.first+l<=c.second)sg.insert({c.first+l,c.second});
            }else{
                a[c.first+l/2]=nxt;
                nxt++;
                l/=2;
                sg.erase(sg.begin());
                if(l==0)continue;
                if(l>0)sg.insert({c.first,c.first+l-1});
                if(c.first+l<c.second)sg.insert({c.first+l+1,c.second});
            }
        }
        for(int i=1;i<=n;i++)printf("%i ",a[i]);
        printf("\n");
    }
    return 0;
}