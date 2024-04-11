#include <bits/stdc++.h>

using namespace std;

const int N=3e5+10;
const int layer=30;

int n,a[N];
struct node{
        node* link[2];
        int sub;
        node(node* left=NULL,node* right=NULL){
                link[0]=left;
                link[1]=right;
                sub=0;
        }
};

int main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        node *root=new node();
        for(int i=1;i<=n;i++){
                int val;
                cin>>val;
                node *cur=root;
                for(int j=layer-1;j>=0;j--){
                        int cbit=(val>>j)&1;
                        if (cur->link[cbit]==NULL)
                                cur->link[cbit]=new node();
                        cur=cur->link[cbit];
                        cur->sub++;
                }
        }
        for(int i=1;i<=n;i++){
                int val=0;
                node *cur=root;
                for(int j=layer-1;j>=0;j--){
                        int cbit=(a[i]>>j)&1;
                        int wanted=cbit;
                        if (cur->link[wanted]==NULL||cur->link[wanted]->sub==0) wanted^=1;
                        val=val*2+(wanted^cbit);
                        cur=cur->link[wanted];
                        cur->sub--;
                }
                cout<<val<<" ";
        }
}