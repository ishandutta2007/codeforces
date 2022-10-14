#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
const int M=2*N;
struct Node{
    int val,op,cl;
    Node(){}
    Node(int x,int y,int z):val(x),op(y),cl(y){}
}st[M];
int n,root,ls[M],rs[M],tsz;
string s;
void Build(int&c,int ss,int se){
    c=++tsz;
    if(ss==se){
        if(s[ss]=='(')st[c].op=1;
        if(s[ss]==')')st[c].cl=1;
        st[c].val=0;
        return;
    }
    int mid=ss+se>>1;
    Build(ls[c],ss,mid);
    Build(rs[c],mid+1,se);
    int x=min(st[ls[c]].op,st[rs[c]].cl);
    st[c].val=st[ls[c]].val+st[rs[c]].val+x*2;
    st[c].op=st[ls[c]].op+st[rs[c]].op-x;
    st[c].cl=st[ls[c]].cl+st[rs[c]].cl-x;
}
Node Get(int c,int ss,int se,int sl,int sr){
    if(ss>se||ss>sr||se<sl)return Node(0,0,0);
    if(sl<=ss&&se<=sr)return st[c];
    int mid=ss+se>>1;
    Node L=Get(ls[c],ss,mid,sl,sr);
    Node R=Get(rs[c],mid+1,se,sl,sr);
    Node ret;
    int x=min(L.op,R.cl);
    ret.val=L.val+R.val+x*2;
    ret.op=L.op+R.op-x;
    ret.cl=L.cl+R.cl-x;
    //cout<<ret.val<<" "<<ss<<" "<<se<<endl;
    return ret;
}
int main(){
    cin>>s;
    n=s.size();
    Build(root,0,n-1);
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        --l;--r;
        cout<<Get(root,0,n-1,l,r).val<<"\n";
    }
    return 0;
}