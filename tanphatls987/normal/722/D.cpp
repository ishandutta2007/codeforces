#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int inf=1e9+10;
int n,p[60];
int a[N];
vector <int> nans;
struct node{
    int sub,tr;
    node *link[2];
    node(){
        sub=0;
        link[0]=link[1]=NULL;
    }
};
node *root;
int DFS(node *cur,int val,int cap){
    int ans=cur->sub;
    for(int i=0;i<=1;i++) if (cur->link[i]!=NULL)
        ans+=DFS(cur->link[i],val*2+i,cap);
    if (val<=cap&&ans) {
        ans--;
        nans.push_back(val);
    }
    return ans;
}
bool check(int mid){
    nans.clear();
    return DFS(root->link[1],1,mid)==0;
}
int main(){
    root=new node();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        int n1=0;
        while (a[i]){
            p[++n1]=a[i]&1;
            a[i]>>=1;
        }
        node *cur=root;
        reverse(p+1,p+n1+1);
        for(int i=1;i<=n1;i++){
            if (cur->link[p[i]]==NULL) cur->link[p[i]]=new node();
            cur=cur->link[p[i]];
        }
        cur->sub=1;
    }
    int L=1,R=inf;
    while (L<=R){
        int mid=(L+R)/2;
        if (check(mid)) R=mid-1;
        else L=mid+1;
    }
    check(L);
//    cout<<L<<'\n';
    for(int i=0;i<n;i++) printf("%d ",nans[i]);
}