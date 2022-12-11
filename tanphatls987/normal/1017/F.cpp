#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;

#define X first
#define Y second

unsigned int n,a[4];
struct mbitset{
        long long a[1562502];
        void add(int i){
                int type=i%6;
                if (type!=1&&type!=5) return;
                int rpos=(i/6)*2+(type==5);
                a[rpos/64]|=1LL<<(rpos&63);
        }
        int get(int i,int type){
                i=i*2+type;
                return (a[i/64]&(1LL<<(i&63)))!=0;
        }
}msieve;
unsigned int process(unsigned int i,unsigned int n){
        if (i>n) return 0;
        unsigned int cur=i;
        unsigned int ans=0;
        while (1){
                unsigned int rep=n/cur;
                ans+=rep;
                if (1LL*cur*i>n) break;
                cur*=i;
        }
        unsigned int add=0;
        for(int j=3;j>=0;j--) add=add*i+a[j];
        return ans*add;
}

void cover(int cur){
        for(int i1=2;cur*i1<=n;i1++)
                msieve.add(cur*i1);
}
int main(){
        cin>>n;
        for(int i=3;i>=0;i--) cin>>a[i];
        unsigned int ans=process(2,n)+process(3,n)+process(5,n);
        cover(5); 
        for(int i=1;i*6<=n;i++){
                for(int j=0;j<=1;j++) if (msieve.get(i,j)==0){
                        int cur=6*i+1+j*4;
                        ans+=process(cur,n);
                        cover(cur);
                }
        }
        cout<<ans;
}