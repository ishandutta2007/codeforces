#include<bits/stdc++.h>
using namespace std;
const int N=105;
int t,n,k;
struct node{
    int a,b;
    bool operator<(const node kk)const{
        return a>kk.a;
    }
}yy[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int kk=k;
        for(int i=1;i<=n;i++){
            scanf("%d",&yy[i].a);
        }
        for(int i=1;i<=n;i++)scanf("%d",&yy[i].b);
        priority_queue<node>q;
        for(int i=1;i<=n;i++)q.push(yy[i]);
        while(q.size()){
            node now=q.top();
            q.pop();
            if(k>=now.a)k+=now.b;
            else break;
        }
        printf("%d\n",k);
    }
    return  0;
}