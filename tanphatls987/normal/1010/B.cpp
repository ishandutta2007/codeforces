#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;
#define X first
#define Y second

const int inf=1e9+10;
const int N=1e3+10;
const double eps=1e-12;


int a[30];

int ask(int pos){
        cout<<pos<<endl;
        fflush(stdout);
        int val;
        cin>>val;
        if (val==0) exit(0);
        return val;
}
int main(){
        int m,n;
        cin>>m>>n;
        for(int i=0;i<n;i++) a[i]=ask(1);
        int ans=0,use=0;
        for(int i=0;i<30;i++){
                int cur=ans+(1<<(29-i));
                if (cur>m) continue;
                int rans=ask(cur)*a[use%n];
                use++;
                if (rans==1) ans=cur;
        }
        return 0;
}