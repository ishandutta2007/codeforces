#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
int A[300000],B[300000],n,l,x[200000],len1,len2,l2,l1;
map<int,int>S;
int main(){
    scanf("%d%d%d%d",&n,&l,&l1,&l2);
    for (int i=1;i<=n;i++) {scanf("%d",&x[i]); S[x[i]]=1;}
    int flag=0;
    for (int i=1;i<=n;i++){
        if (x[i]>=l1){
            A[++len1]=x[i]-l1; if (S[A[len1]]) {flag+=1; break;}
        }
        if (x[i]+l1<=l){
            A[++len1]=x[i]+l1; if (S[A[len1]]) {flag+=1; break;}
        }
    }
    for (int i=1;i<=n;i++){
        if (x[i]>=l2){
            B[++len2]=x[i]-l2; if (S[B[len2]]) {flag+=2; break;}
        }
        if (x[i]+l2<=l){
            B[++len2]=x[i]+l2; if (S[B[len2]]) {flag+=2; break;}
        }
    }
    sort(A+1,A+len1+1); sort(B+1,B+len2+1);
    if (flag==3){cout<<0<<endl; return 0;}
    if (flag==2){
        cout<<1<<endl; cout<<A[1]<<endl; return 0;
    }
    if (flag==1){
        cout<<1<<endl; cout<<B[1]<<endl; return 0;
    }
    int now=1;
    for (int i=1;i<=len1;i++){
        while (now<=len2&&B[now]<A[i]) now++;
        if (now<=len2&&B[now]==A[i]){
            cout<<1<<endl; cout<<B[now]<<endl; return 0;
        }
    }
    cout<<2<<endl;
    cout<<A[1]<<" "<<B[1]<<endl; return 0;
}